#include "AppDelegate.h"

#include "MainScene.h"
#include "audio/AudioEngine.h"

using namespace ax;

namespace {
const Size kDesignResolution(1136.0F, 640.0F);
}

AppDelegate::AppDelegate() = default;
AppDelegate::~AppDelegate() = default;

void AppDelegate::initGfxContextAttrs() {
    GfxContextAttrs attrs = {8, 8, 8, 8, 24, 8, 0};
    RenderView::setGfxContextAttrs(attrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto* director = Director::getInstance();
    auto* renderView = director->getRenderView();
    if (renderView == nullptr) {
#if (AX_TARGET_PLATFORM != AX_PLATFORM_ANDROID) && (AX_TARGET_PLATFORM != AX_PLATFORM_IOS)
        renderView = RenderViewImpl::createWithRect(
            "Magic Maker Axmol", Rect(0, 0, kDesignResolution.width, kDesignResolution.height));
#else
        renderView = RenderViewImpl::create("Magic Maker Axmol");
#endif
        director->setRenderView(renderView);
    }

    director->setStatsDisplay(false);
    director->setAnimationInterval(1.0F / 60.0F);
    renderView->setDesignResolutionSize(
        kDesignResolution.width, kDesignResolution.height, ResolutionPolicy::SHOW_ALL);

    FileUtils::getInstance()->addSearchPath("");

    auto* scene = utils::createInstance<MainScene>();
    director->runWithScene(scene);
    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    AudioEngine::pauseAll();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    AudioEngine::resumeAll();
}
