// Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license

#pragma once

#include "utils.h"
#include "renderer.h"  // TODO: Stroke has a RenderElement
                       // member. Refactor to eliminate this
                       // dependency

struct Brush
{
    i32 radius;  // In pixels. See milton->brush_sizes for canvas-space sizes.
    v4f color;
    f32 _alpha;
    f32 _pressure_opacity_min;  // Opacity from pressure.
    f32 _hardness;
};

// TODO: These should be brush flags. Probably want to do it when we add a new member to the Brush struct..
enum StrokeFlag
{
    StrokeFlag_ERASER               = (1<<2),
};

struct Stroke
{
    i32             id;

    Brush           brush;
    v2l*            points;
    f32*            pressures;
    i32             num_points;
    Rect            bounding_rect;
    RenderHandle    render_handle;

    u32 flags; // StrokeFlag

#if STROKE_DEBUG_VIZ
    enum DebugFlags
    {
        NONE = (0),
        INTERPOLATED  = (1<<0),
    };
    int* debug_flags;
#endif
};

static inline Brush default_brush()
{
    Brush brush = {};
    brush.radius = 10240;
    return brush;
}