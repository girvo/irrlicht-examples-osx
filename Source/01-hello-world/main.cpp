#include <iostream>
#include <irrlicht/irrlicht.h>
#include <json/json.h>

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv)
{
    // Create our base irrlicht engine device
    IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE, dimension2d<u32>(SCREEN_WIDTH, SCREEN_HEIGHT), 16, false, false, false, 0);

    if (!device) {
        return 1;
    }

    // Sets up video driver, scene manager and gui env
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* sceneManager = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
        rect<s32>(10, 10, 260, 22), true);

    while (device->run()) {
        driver->beginScene(true, true, SColor(255, 100, 101, 140));

        sceneManager->drawAll();
        guienv->drawAll();

        driver->endScene();
    }

    device->drop();

    return 0;
}
