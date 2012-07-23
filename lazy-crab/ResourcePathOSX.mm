////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2012 Marco Antognini (antognini.marco@gmail.com), 
//                         Laurent Gomila (laurent.gom@gmail.com), 
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
// 
// CUSTOM ADDITIONS BY MUNGOGAMES
//
// DEBUG switch resourcepaths. If in DEBUG mode, use the data from the folder next to it 
// (no compiling needed if new resources will be added)
//
// If not in DEBUG mode the data from within the app will be used
//
// With this enhancement creating new content is possible without recompiling and in final versions
// or open alphas/betas the app is just in one place
//
////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "ResourcePathOSX.hpp"
#import <Foundation/Foundation.h>

////////////////////////////////////////////////////////////
std::string resourcePathOSX(void)
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    
	std::string rpath;
	NSBundle* bundle = [NSBundle mainBundle];

	if (bundle == nil) {
#ifdef DEBUG
		NSLog(@"bundle is nil... thus no resources path can be found.");
#endif
	} else {
		NSString* path = [bundle resourcePath];
#ifdef DEBUG
    rpath = "data/"; // if debuging/testing, don't use the resources in the app but the ones in the data folder next to it
#else
    rpath = [path UTF8String] + std::string("/data/"); // if not a developer version, use the resources in the app
#eindif
	}
    
    [pool drain];
    
    return rpath;
}
