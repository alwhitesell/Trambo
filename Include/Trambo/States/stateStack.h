#ifndef TRAMBO_STATE_STACK_H
#define TRAMBO_STATE_STACK_H

#include "state.h"

#include <SFML/System/NonCopyable.hpp>

#include <functional>
#include <map>
#include <utility>
#include <vector>


namespace sf
{
	class Time;
}

namespace States
{
	enum class ID;
}

namespace trmb
{

class StateStack : private sf::NonCopyable
{
public:
	enum class Action
	{
		Push,
		Pop,
		Clear,
	};


public:
	explicit			StateStack(State::Context context);

	template <typename T>
	void				registerState(States::ID stateID);

	void				update(sf::Time dt);
	void				draw();
	void				handleEvent(const sf::Event& event);

	void				pushState(States::ID stateID);
	void				popState();
	void				clearStates();

	bool				isEmpty() const;


private:
	State::Ptr			createState(States::ID stateID);
	void				applyPendingChanges();


private:
	struct PendingChange
	{
		explicit			PendingChange(Action action, States::ID stateID = static_cast<States::ID>(0));   // ALW - substitute '0' for States::ID::None (defined in game)

		Action				action;
		States::ID				stateID;
	};


private:
	std::vector<State::Ptr>								mStack;
	std::vector<PendingChange>							mPendingList;
	
	State::Context										mContext;
	std::map<States::ID, std::function<State::Ptr()>>	mFactories;
};

template <typename T>
void StateStack::registerState(States::ID stateID)
{
	mFactories[stateID] = [this] ()
	{
		return State::Ptr(new T(*this, mContext));
	};
}

} // trmb namespace

#endif
