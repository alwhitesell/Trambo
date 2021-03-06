#ifndef TRAMBO_ACTIONBINDING_H
#define TRAMBO_ACTIONBINDING_H

#include "../Inputs/action.h"
#include "../Inputs/JoystickAxisAsButton.h"
#include "../Inputs/JoystickButtonAsButton.h"
#include "../Inputs/keyboardKeyAsButton.h"
#include "../Inputs/MouseButtonAsButton.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <memory>
#include <utility>
#include <vector>


namespace sf
{
	class Event;
}

namespace trmb
{

class ActionBinding
{
public:
	typedef unsigned long EventGuid;
	typedef std::shared_ptr<Action> ActionSharedPtr;


public:
										ActionBinding();
										ActionBinding(const ActionBinding &) = delete;
	ActionBinding &						operator=(const ActionBinding &) = delete;

	const std::vector<ActionSharedPtr>& getActions() const;
	sf::Keyboard::Key					getInputFromKeyboardKeyAsButtonBinding(EventGuid eventGuid) const;
	sf::Mouse::Button					getInputFromMouseButtonAsButtonBinding(EventGuid eventGuid) const;

	void					update();
	void					handleEvent(const sf::Event& inputEvent);

	void					createAction(EventGuid eventGuid);
	void					assignKeyboardKeyAsButtonBinding(const KeyboardKeyAsButton& keyboardKeyAsButton, EventGuid eventGuid);
	void					assignMouseButtonAsButtonBinding(const MouseButtonAsButton& mouseButtonAsButton, EventGuid eventGuid);
	void					assignJoystickButtonAsButtonBinding(const JoystickButtonAsButton& joystickButtonAsButton, EventGuid eventGuid);
	void					assignJoystickAxisAsButtonBinding(const JoystickAxisAsButton& joystickAxisAsButton, EventGuid eventGuid);


private:
	typedef std::weak_ptr<Action> ActionWeakPtr;


private:
	void					removeDuplicateActionsInKeyboardKeysAsButtonBindings(EventGuid eventGuid);
	void					removeDuplicateActionsInMouseButtonsAsButtonBindings(EventGuid eventGuid);
	void					removeDuplicateActionsInJoystickButtonsAsButtonBindings(EventGuid eventGuid);
	void					removeDuplicateActionsInJoystickAxesAsButtonBindings(EventGuid eventGuid);

	ActionWeakPtr			getWeakPtrToAction(EventGuid eventGuid) const;


private:
	std::vector<ActionSharedPtr>								  mActions; // ALW - Once added, elements should not be deleted.
	std::vector<std::pair<KeyboardKeyAsButton, ActionWeakPtr>>	  mKeyboardKeysAsButtonBindings;
	std::vector<std::pair<MouseButtonAsButton, ActionWeakPtr>>	  mMouseButtonsAsButtonBindings;
	std::vector<std::pair<JoystickButtonAsButton, ActionWeakPtr>> mJoystickButtonsAsButtonBindings;
	std::vector<std::pair<JoystickAxisAsButton, ActionWeakPtr>>   mJoystickAxesAsButtonBindings;
};

} // namespace trmb

#endif
