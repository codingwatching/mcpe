/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#include <fstream>

#include "AppPlatform.hpp"
#include "common/Utils.hpp"

AppPlatform* AppPlatform::m_singleton = nullptr;

AppPlatform* const AppPlatform::singleton()
{
	return m_singleton;
}

AppPlatform::AppPlatform()
{
	m_singleton = this;
}

AppPlatform::~AppPlatform()
{

}

void AppPlatform::_tick()
{

}

void AppPlatform::buyGame()
{

}

int AppPlatform::checkLicense()
{
	return 0; // assume no license
}

void AppPlatform::createUserInput()
{

}

void AppPlatform::finish()
{

}

std::string AppPlatform::getDateString(int time)
{
	return "";
}

// ??? AppPlatform::getOptionStrings()
// To whoever is confused about the above, we moved it to Options::getOptionStrings()

int AppPlatform::getScreenWidth() const
{
	return C_DEFAULT_SCREEN_WIDTH; // default rez of the XPERIA PLAY?
}

int AppPlatform::getScreenHeight() const
{
	return C_DEFAULT_SCREEN_HEIGHT;
}

std::vector<std::string> AppPlatform::getUserInput()
{
	return std::vector<std::string>();
}

int AppPlatform::getUserInputStatus()
{
	return 0;
}

bool AppPlatform::hasBuyButtonWhenInvalidLicense()
{
	return false;
}

// void AppPlatform::loadTexture(const std::string&, bool);

void AppPlatform::saveScreenshot(const std::string&, int, int)
{

}

void AppPlatform::showDialog(eDialogType type)
{

}

void AppPlatform::uploadPlatformDependentData(int, void*)
{

}


Texture AppPlatform::loadTexture(const std::string&, bool bIsRequired)
{
	return Texture(0, 0, nullptr, 1, 0);
}

#ifndef ORIGINAL_CODE

bool AppPlatform::doesTextureExist(const std::string& path) const
{
	return false;
}

bool AppPlatform::isTouchscreen() const
{
	return true;
}

bool AppPlatform::hasGamepad() const
{
	return false;
}

void AppPlatform::recenterMouse()
{

}

void AppPlatform::setMouseGrabbed(bool b)
{

}

void AppPlatform::getMouseDiff(int& x, int& y)
{
	x = y = 0;
}

void AppPlatform::clearDiff()
{
	
}

void AppPlatform::updateFocused(bool focused)
{
}

bool AppPlatform::shiftPressed()
{
	return false;
}

void AppPlatform::showKeyboard(int x, int y, int w, int h)
{
	showKeyboard();
}

void AppPlatform::showKeyboard()
{
}

void AppPlatform::showKeyboard(bool bShown)
{
	if (bShown)
		showKeyboard();
	else
		hideKeyboard();
}

void AppPlatform::hideKeyboard()
{
}

void AppPlatform::onHideKeyboard()
{
}

#ifdef USE_NATIVE_ANDROID
int AppPlatform::getKeyboardUpOffset()
{
	return 0;
}
#endif

void AppPlatform::vibrate(int milliSeconds)
{
}

void AppPlatform::_fireLowMemory()
{
	
}

void AppPlatform::_fireAppSuspended()
{
	
}

void AppPlatform::_fireAppResumed()
{
	
}

void AppPlatform::_fireAppFocusLost()
{
	
}

void AppPlatform::_fireAppFocusGained()
{
	
}

void AppPlatform::_fireAppTerminated()
{
	
}

bool AppPlatform::hasFileSystemAccess()
{
	return false;
}

std::string AppPlatform::getPatchData()
{
	const AssetFile file = readAssetFile("patches/patch_data.txt", false);
	std::string out = std::string(file.data, file.data + file.size);
	delete file.data;
	return out;
}

AssetFile AppPlatform::readAssetFile(const std::string& path, bool quiet) const
{
	std::string realPath = getAssetPath(path);
	std::ifstream ifs(realPath.c_str());
    
	// Open File
	if (!ifs.is_open())
	{
		if (!quiet) LOG_W("Couldn't find asset file: %s", realPath.c_str());
		return AssetFile();
	}
    
    std::filebuf* pbuf = ifs.rdbuf();
    
	// Get File Size
    std::streamoff size = pbuf->pubseekoff(0, ifs.end, ifs.in);
    pbuf->pubseekpos(0, ifs.in);
	if (size < 0)
	{
		if (!quiet) LOG_E("Error determining the size of the asset file!");
		ifs.close();
		return AssetFile();
	}
    
	// Read Data
	char *buf = new char[size];
    pbuf->sgetn(buf, (std::streamsize)size);
    
	// Close File
    ifs.close();
    
	// Return
	return AssetFile((int64_t)size, (unsigned char*)buf);
}

void AppPlatform::initSoundSystem()
{
}

SoundSystem* const AppPlatform::getSoundSystem() const
{
	return nullptr;
}

#endif

std::string AppPlatform::getAssetPath(const std::string &path) const
{
	std::string realPath = path;
	if (realPath.size() && realPath[0] == '/')
	{
		// trim it off
		realPath = realPath.substr(1);
	}
	realPath = "assets/" + realPath;
	
	return realPath;
}
