#ifndef BASICAPP_H
#define BASICAPP_H

#include <OgreRoot.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OgreException.h>
#include <OgreEntity.h>
#include <OgreFrameListener.h>
#include <OgreWindowEventUtilities.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <SdkCameraMan.h>

class BasicApp
    : public Ogre::WindowEventListener,
      public Ogre::FrameListener,
      public OIS::KeyListener,
      public OIS::MouseListener
{
public:
    BasicApp();
    ~BasicApp();

    void go();

private:
    virtual bool frameRenderingQueued(const Ogre::FrameEvent &fe);

    virtual bool keyPressed(const OIS::KeyEvent &ke);
    virtual bool keyReleased(const OIS::KeyEvent &ke);

    virtual bool mouseMoved(const OIS::MouseEvent &me);
    virtual bool mousePressed(const OIS::MouseEvent &me, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &me, OIS::MouseButtonID id);

    virtual void windowResized(Ogre::RenderWindow *rw);
    virtual void windowClosed(Ogre::RenderWindow *rw);

    bool setup();
    bool configure();
    void chooseSceneManager();
    void createCamera();
    void createScene();
    void destroyScene();
    void createFrameListener();
    void createViewports();
    void setupResources();
    void createResourceListener();
    void loadResources();

    bool mShutdown;

    Ogre::Root *mRoot;
    Ogre::Camera *mCamera;
    Ogre::SceneManager *mSceneMgr;
    Ogre::RenderWindow *mWindow;
    Ogre::String mResourcesCfg;
    Ogre::String mPluginsCfg;

    OgreBites::SdkCameraMan *mCameraMan;

    // OIS
    OIS::Mouse *mMouse;
    OIS::Keyboard *mKeyboard;
    OIS::InputManager *mInputMgr;

    //////////////////////
    // Tutorial Section //
    //////////////////////
    bool nextLocation();

    std::deque<Ogre::Vector3> mWalkList;

    Ogre::Real mDistance;
    Ogre::Real mWalkSpd;
    Ogre::Vector3 mDirection;
    Ogre::Vector3 mDestination;
    Ogre::AnimationState *mAnimationState;
    Ogre::Entity *mEntity;
    Ogre::SceneNode *mNode;
};

#endif