//
//  KeyboardAnimator.h
//
//  Created by Ratul Sharker on 8/4/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


//    These are the customization macro which are set to default values.
//    Change the values to complete you need
#define DEFAULT_KEYBOARD_UP_ANIMATION_DURATION          0.5f
#define DEFAULT_KEYBOARD_DOWN_ANIMATION_DURATION        0.25F
#define DEFAULT_SPACING_BETWEEN_TEXTFIELD_AND_KEYBOARD  15.0f


enum KeyboardAnimatorDurationType
{
    KEYBOARD_ANIMATION_DURATION_TYPE_PROVIDED,
    KEYBOARD_ANIMATION_DURATION_TYPE_AS_KEYBOARD
};


#define DEFAULT_KEYBOARD_ANIMATE_UP_EVENT               UIKeyboardDidShowNotification
#define DEFAULT_KEYBOARD_ANIMATE_DOWN_EVENT             UIKeyboardDidHideNotification


@interface KeyboardAnimator : NSObject



//    This is the simple initializer of the keyboard animator.
//    To initialize properly provide an NSArray of UITextField and the UIView object which will be actually animated.
//    For most of the case, animatedView param will be the ViewController's self.view
-(id)initKeyboardAnimatorWithTextFieldArray:(NSArray*)tf
                   AndWhichViewWillAnimated:(UIView*)view
                          bottomConstraints:(NSArray*)bottomConstraints
                       nonBottomConstraints:(NSArray*)nonBottomConstraints;


//    This is little bit complex initialization
//    where we will provide a two NSArray where. Two parameters named textFields & targetTextFields
//    The first array is the responsible textField, for whom the elevation will occur. The second will be targeted text field, upto
//    which the elevation will occur.

//    for example, say we have 3 UITextFields named TF1, TF2, TF3 and they are placed in the GUI as following
//
//      |---------|
//      |---TF1---|
//      |---TF2---|
//      |---TF3---|
//      |---------|
//
//    And we want to animate the keyboard just under the TF3 for every UITextFields.
//
//    To get this kind of functionality, we may use this initializer.
//    To achieve the discussed result we will initializer as following :
//
//  @param textFields
//      @[TF1, TF2, TF3]
//
//
//  @param targetTextField
//      @[TF3, TF3, TF3]
//
//  here textFieldMapping's key will be all the UITextField which we are interested to animate,
//  and value of those key's will be the resulting animated UITextField. So here for all UITextField
//  we will animate upto TF3.
-(id)initKeyboardAnimatorWithTextField:(NSArray*)tf
                   withTargetTextField:(NSArray*)targetTf
              AndWhichViewWillAnimated:(UIView*)animatedView
                     bottomConstraints:(NSArray*)bottomConstraints
                  nonBottomConstraints:(NSArray*)nonBottomConstraints;



//    Add a simple notification on keyboard change UIKeyboardDidShowNotification & UIKeyboardDidHideNotification
//    notification. These notification will trigger when keyboard will appear and disappear.
//    It is recommended to call this method in the viewWillAppear / viewDidAppear method of the UIViewController
-(void)registerKeyboardEventListener;

//    Adding a notification change listener add a overhead. Before getting out from the target viewController, you
//    must clean up the mess. Thats why this function will help you to remove the keyboard change notification.
//    It is recommended to call this method in the viewWillDisappear / viewDidDisappear of the UIVIewController
-(void)unregisterKeyboardEventListener;

//    Here are some additional param settings
//    These are the optional things you are about to customize your
//    view animations

//    keep in mind, except you set these following
//    properties, default value declared in the macro
//    will be used. macros are declared at the first
//    of this file

//    set the time interval of keyboard is moving up
//    it wont make keyboard appear faster, otherwise
//    it will animate the corresponding view according to the given time
-(void) setKeyboardUpAnimationDuration:(NSTimeInterval)uptimeInterval;

//    set the time interval of keyboard moving down
//    it wont make the keyboard disappear faster, otherwise
//    it will animate the corresponding view according to the given time
-(void) setKeyboardDownAnimationDuration:(NSTimeInterval)downTimeInterval;

//    set spacing between the keyboard and the targeted textField
-(void) setSpacingBetweenKeyboardAndTargetedTextField:(CGFloat)spacing;


//    set the action which will fire the animation up
//
//    NB :: to apply effectively set the value before "registerKeyboardEventListener"
//          if the case is such that, need a dynamic effect, you should unregister the event listerner
//          using "unregisterKeyboardEventListener" then re-register using "registerKeyboardEventListener"
//          after calling this method
//
//    @param animateUpEvent
//      valid values for animateUpEvent are
//      1. UIKeyboardDidShowNotification
//      2. UIKeyboardWillShowNotification
-(void) setKeyboardUpAnimationOn:(NSString*)animateUpEvent;


//    set the action which will fire the animation down
//
//    NB :: to apply effectively set the value before "registerKeyboardEventListener"
//          if the case is such that, need a dynamic effect, you should unregister the event listerner
//          using "unregisterKeyboardEventListener" then re-register using "registerKeyboardEventListener"
//          after calling this method
//
//    @param animateDownEvent
//      valid values for animateUpEvent are
//      1. UIKeyboardDidHideNotification
//      2. UIKeyboardWillHideNotification
-(void) setKeyboardDownAnimationOn:(NSString*)animateDownEvent;


// in still devlopment
-(void) setKeyboardAnimationIntervalType:(enum KeyboardAnimatorDurationType)durationType;
@end
