// Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license


#pragma once

#include "vector.h"
#include "StrokeList.h"

struct Layer
{
    i32 id;

    StrokeList strokes;

    i32 _flags;

    Layer* prev;
    Layer* next;
};

#pragma pack (push, 1)

// IMPORTANT: CanvasView needs to be a flat structure
//            because the whole struct is saved to the mlt file.
//            It should only grow down.
struct CanvasView
{
    u32 size;                   // Size of struct
    v2i screen_size;            // Size in pixels
    i64 _scale;                 // Zoom
    v2i _zoom_center;            // In pixels
    v2l pan_center;             // In canvas scale
    v3f background_color;
    i32 working_layer_id;
    f32 _angle;                 // Rotation
};

#pragma pack(pop)


v2l     canvas_to_raster (CanvasView* view, v2l canvas_point);
v2l     raster_to_canvas (CanvasView* view, v2l raster_point);

b32     stroke_point_contains_point (v2l p0, i64 r0, v2l p1, i64 r1);  // Does point p0 with radius r0 contain point p1 with radius r1?
Rect    bounding_box_for_stroke (Stroke* stroke);
Rect    bounding_box_for_last_n_points (Stroke* stroke, i32 last_n);

Rect    raster_to_canvas_bounding_rect(CanvasView* view, i32 x, i32 y, i32 w, i32 h, i64 scale);
Rect    canvas_to_raster_bounding_rect(CanvasView* view, Rect rect);

void    reset_transform_at_origin(v2l* pan_center);

// ---- Layer functions.
namespace layer {
    Layer*  get_topmost (Layer* root);
    Layer*  get_by_id (Layer* root_layer, i32 id);
    Stroke* layer_push_stroke (Layer* layer, Stroke stroke);
    i32     number_of_layers (Layer* root);
    void    free_layers (Layer* root);
    i64     count_strokes (Layer* root);
    i64     count_clipped_strokes (Layer* root, i32 num_workers);
}