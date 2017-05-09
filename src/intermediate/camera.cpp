#include "camera.h"
Camera::Camera()
    : Camera(0, 0)
{
}

Camera::Camera(Ogre::SceneManager *sceneMgr, Ogre::RenderWindow *window)
    : spd(10), turn_spd(12), pitch_spd(4), cam_node(0), pitch_node(0)
{
    init(sceneMgr, window);
}

void Camera::init(Ogre::SceneManager *sceneMgr, Ogre::RenderWindow *window)
{
    mSceneMgr = sceneMgr;
    mWindow   = window;
    m_node    = mSceneMgr->getRootSceneNode()->createChildSceneNode();

    cam = mSceneMgr->createCamera("UserCamera");
    cam->setNearClipDistance(.1);

    cam_node = m_node->createChildSceneNode();
    cam_node->setPosition(0, -15, 30);
    float cam_pitch = 30.0 / 180 * M_PI;
    cam_node->setOrientation(cos(cam_pitch / 2.0), sin(cam_pitch / 2.0), 0.0, 0.0);
    pitch_node = cam_node->createChildSceneNode();
    pitch_node->attachObject(cam);

    initViewports();
}

void Camera::initViewports()
{
    Ogre::Viewport *vp =
        mWindow->addViewport(cam);
    vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

    cam->setAspectRatio(
        Ogre::Real(vp->getActualWidth()) /
        Ogre::Real(vp->getActualHeight()));
}
