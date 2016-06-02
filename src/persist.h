// Copyright (c) 2015-2016 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license


#pragma once


void milton_load(MiltonState* milton_state);

void milton_save(MiltonState* milton_state);

void milton_prefs_load(PlatformPrefs* prefs);
void milton_prefs_save(PlatformPrefs* prefs);

void milton_save_buffer_to_file(char* fname, u8* buffer, i32 w, i32 h);

// Open Milton with the last used canvas.
void milton_set_last_canvas_fname(char* last_fname);
void milton_unset_last_canvas_fname();

char* milton_get_last_canvas_fname();


