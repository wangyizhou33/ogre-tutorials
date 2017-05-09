#ifndef CAMERA_H
#define CAMERA_H

#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>

class Camera
{
public:
    Camera();
    Camera(Ogre::SceneManager *sceneMgr, Ogre::RenderWindow *window);
    ~Camera() = default;

    void init(Ogre::SceneManager *sceneMgr, Ogre::RenderWindow *window);
    void update(float dt);

    Ogre::SceneNode *getNode()
    {
        return m_node;
    }
    Ogre::Camera *getOgreCamera()
    {
        return cam;
    }

private:
    void initViewports();

    float spd, turn_spd, pitch_spd;
    Ogre::SceneManager *mSceneMgr;
    Ogre::RenderWindow *mWindow;
    Ogre::Camera *cam;
    Ogre::SceneNode *m_node;
    Ogre::SceneNode *cam_node;
    Ogre::SceneNode *pitch_node;

};     // class Camera
#endif // CAMERA_H