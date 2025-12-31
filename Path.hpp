/* 
 * 
 * The Path component represents a connection between scenes. The Path defines the command(s) used to move between scenes.
 * A path may respond to multiple commands, although one path will always lead to one scene.
 * A scene connected to multiple others should use multiple paths.
 * Some examples of Path components include: 
 *  - Doors, which may change scenes with a command such as "Enter door"
 *  - Cardinal directions, which would be path components with commands such as "Walk north"
 * 
 */
#pragma once
#include <string>
using namespace std;

struct Path {
	string useMessage; //The message sent to use the path.
};