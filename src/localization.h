// Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license

#pragma once


void init_localization();


// Re-ordering is OK.
enum Texts
{
    TXT_file,
    TXT_open_milton_canvas,
    TXT_export_to_image_DOTS,
    TXT_quit,
    TXT_canvas,
    TXT_help,
    TXT_brushes,
    TXT_opacity,
    TXT_brush_size,
    TXT_switch_to_brush,
    TXT_switch_to_eraser,
    TXT_set_background_color,
    TXT_choose_background_color,
    TXT_default_background_color,
    TXT_color,
    TXT_export_DOTS,
    TXT_MSG_click_and_drag_instruction,
    TXT_current_selection,
    TXT_scale_up,
    TXT_final_image_resolution,
    TXT_export_selection_to_image_DOTS,
    TXT_MSG_memerr_did_not_write,
    TXT_error,
    TXT_cancel,
    TXT_view,
    TXT_toggle_gui_visibility,

    // ==== Translation to spanish completed until this point

    TXT_settings,
    TXT_switch_to_primitive_line,
    TXT_switch_to_primitive_rectangle,
    TXT_switch_to_primitive_grid,
    TXT_help_me,
    TXT_move,
    TXT_move_canvas,
    TXT_stop_moving_canvas,
    TXT_up,
    TXT_down,
    TXT_are_you_sure,
    TXT_cant_be_undone,
    TXT_yes,
    TXT_no,
    TXT_ok,
    TXT_delete,
    TXT_edit,
    TXT_undo,
    TXT_redo,
    TXT_tools,
    TXT_brush,
    TXT_eraser,
    TXT_brush_options,
    TXT_set_opacity_to,
    TXT_save_milton_canvas_as_DOTS,
    TXT_new_milton_canvas,
    TXT_decrease_brush_size,
    TXT_increase_brush_size,
    TXT_eye_dropper,
    TXT_milton_version,
    TXT_website,
    TXT_disable_stroke_smoothing,
    TXT_enable_stroke_smoothing,
    TXT_transparent_background,
    TXT_set_current_background_color_as_default,
    TXT_background_color,
    TXT_OPENBRACKET_default_canvas_CLOSE_BRACKET,
    TXT_background_COLON,
    TXT_could_not_delete_default_canvas,
    TXT_opacity_pressure,
    TXT_soft_brush,
    TXT_minimum,
    TXT_hardness,
    TXT_rotation,
    TXT_level,
    TXT_enabled,
    TXT_default_will_be_cleared,
    TXT_reset_view_at_origin,
    TXT_reset_GUI,
    TXT_size_relative_to_canvas,
    TXT_grid_columns,
    TXT_grid_rows,

    // Actions
    TXT_Action_FIRST,
    TXT_Action_DECREASE_BRUSH_SIZE = TXT_Action_FIRST,
    TXT_Action_INCREASE_BRUSH_SIZE,
    TXT_Action_REDO,
    TXT_Action_UNDO,
    TXT_Action_EXPORT,
    TXT_Action_QUIT,
    TXT_Action_NEW,
    TXT_Action_SAVE,
    TXT_Action_SAVE_AS,
    TXT_Action_OPEN,
    TXT_Action_TOGGLE_MENU,
    TXT_Action_TOGGLE_GUI,
    TXT_Action_MODE_ERASER,
    TXT_Action_MODE_PEN,
    TXT_Action_MODE_EYEDROPPER,
    TXT_Action_MODE_PRIMITIVE_LINE,
    TXT_Action_MODE_PRIMITIVE_RECTANGLE,
    TXT_Action_MODE_PRIMITIVE_GRID,
    TXT_Action_COLOUR_PRESET_1,
    TXT_Action_COLOUR_PRESET_2,
    TXT_Action_COLOUR_PRESET_3,
    TXT_Action_COLOUR_PRESET_4,
    TXT_Action_COLOUR_PRESET_5,
    TXT_Action_COLOUR_PRESET_6,
    TXT_Action_COLOUR_PRESET_7,
    TXT_Action_COLOUR_PRESET_8,
    TXT_Action_COLOUR_PRESET_9,
    TXT_Action_COLOUR_PRESET_0,
    TXT_Action_HELP,
    TXT_Action_DRAG_BRUSH_SIZE,

#if MILTON_ENABLE_PROFILING
    TXT_Action_TOGGLE_DEBUG_WINDOW,
#endif

    TXT_Count,
};

char* loc(Texts id);
