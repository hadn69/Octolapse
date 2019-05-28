////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Octolapse - A plugin for OctoPrint used for making stabilized timelapse videos.
// Copyright(C) 2019  Brad Hochgesang
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This program is free software : you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.If not, see the following :
// https ://github.com/FormerLurker/Octolapse/blob/master/LICENSE
//
// You can contact the author either through the git - hub repository, or at the
// following email address : FormerLurker@pm.me
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SNAPSHOT_PLAN_H
#define SNAPSHOT_PLAN_H
#include "snapshot_plan_step.h"
#include "parsed_command.h"
#include "position.h"
#include "gcode_wiper.h"
#include <vector>
#include <map>
class snapshot_plan
{
public:
	snapshot_plan();
	snapshot_plan(const snapshot_plan & source);
	~snapshot_plan();
	PyObject * to_py_object();
	static PyObject * build_py_object(std::vector<snapshot_plan *> plans);
	long file_line_;
	long file_gcode_number_;
	parsed_command * p_triggering_command_;
	parsed_command * p_start_command_;
	position * p_initial_position_;
	std::vector<snapshot_plan_step*> steps_;
	position * p_return_position_;
	parsed_command * p_end_command_;
	std::vector<gcode_wiper_step*> wipe_steps_;
};

#endif