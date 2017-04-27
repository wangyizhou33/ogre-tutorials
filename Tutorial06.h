#include <OgreRoot.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OgreWindowEventUtilities.h>

class TutorialApplication : public Ogre::WindowEventListener, public Ogre::FrameListener
{
public:
    TutorialApplication();
    virtual ~TutorialApplication();

    bool go();

private:
    // Ogre::WindowEventListener
    virtual void windowResized(Ogre::RenderWindow *rw);
    virtual void windowClosed(Ogre::RenderWindow *rw);
    // Ogre::FrameListener
    virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);

    Ogre::Root *mRoot;
    Ogre::String mResourcesCfg;
    Ogre::String mPluginsCfg;
    Ogre::RenderWindow *mWindow;
    Ogre::SceneManager *mSceneMgr;
    Ogre::Camera *mCamera;
    OIS::InputManager *mInputManager;
    OIS::Mouse *mMouse;
    OIS::Keyboard *mKeyboard;
};