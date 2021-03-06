//========================================================================================
//  
//  $File: $
//  
//  Owner: Kinanu
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:

// General includes:
#include "CActionComponent.h"
#include "CAlert.h"

// Project includes:
#include "LIBID.h"

/** Implements IActionComponent; performs the actions that are executed when the plug-in's
	menu items are selected.

	
	@ingroup librelio

*/
class LIBActionComponent : public CActionComponent
{
public:
/**
 Constructor.
 @param boss interface ptr from boss object on which this interface is aggregated.
 */
		LIBActionComponent(IPMUnknown* boss);

		/** The action component should perform the requested action.
			This is where the menu item's action is taken.
			When a menu item is selected, the Menu Manager determines
			which plug-in is responsible for it, and calls its DoAction
			with the ID for the menu item chosen.

			@param actionID identifies the menu item that was selected.
			@param ac active context
			@param mousePoint contains the global mouse location at time of event causing action (e.g. context menus). kInvalidMousePoint if not relevant.
			@param widget contains the widget that invoked this action. May be nil. 
			*/
		virtual void DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget);

	private:
		/** Encapsulates functionality for the about menu item. */
		void DoAbout();
};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(LIBActionComponent, kLIBActionComponentImpl)

/* LIBActionComponent Constructor
*/
LIBActionComponent::LIBActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/* DoAction
*/
void LIBActionComponent::DoAction(IActiveContext* ac, ActionID actionID, GSysPoint mousePoint, IPMUnknown* widget)
{
	switch (actionID.Get())
	{
        case kLIBAddSlideShowActionID:
        {
//            CAlert::InformationAlert("Add slideshow");
            
            break;
        }
        

		case kLIBPopupAboutThisActionID:
		case kLIBAboutActionID:
		{
			this->DoAbout();
			break;
		}

		default:
		{
			break;
		}
	}
}

/* DoAbout
*/
void LIBActionComponent::DoAbout()
{
	CAlert::ModalAlert
	(
		kLIBAboutBoxStringKey,				// Alert string
		kOKString, 						// OK button
		kNullString, 						// No second button
		kNullString, 						// No third button
		1,							// Set OK button to default
		CAlert::eInformationIcon				// Information icon.
	);
}


