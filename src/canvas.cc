// Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license

#include "canvas.h"
#include "utils.h"

v2l
raster_to_canvas(CanvasView* view, v2l raster_point)
{
    return {
        raster_point.x + view->pan_center.x,
        raster_point.y + view->pan_center.y,
    };
}

v2l
canvas_to_raster(CanvasView* view, v2l canvas_point)
{
    return {
        canvas_point.x - view->pan_center.x,
        canvas_point.y - view->pan_center.y,
    };
}

Rect
raster_to_canvas_bounding_rect(CanvasView* view, i32 x, i32 y, i32 w, i32 h)
{
    Rect result = rect_without_size();

    v2l corners[4] = {
        v2l{ x, y },
        v2l{ x+w, y },
        v2l{ x+w, y+h },
        v2l{ x, y+h },
    };

    for (int i = 0; i < 4; ++i) {
        v2l p = raster_to_canvas(view, corners[i]);
        if (p.x < result.left) {
            result.left = p.x;
        }
        if (p.x > result.right) {
            result.right = p.x;
        }
        if (p.y < result.top) {
            result.top = p.y;
        }
        if (p.y > result.bottom) {
            result.bottom = p.y;
        }
    }

    return result;
}

Rect
canvas_to_raster_bounding_rect(CanvasView* view, Rect rect)
{
    Rect result = rect_without_size();

    v2l corners[4] = {
        v2l{ rect.left, rect.top },
        v2l{ rect.right, rect.top },
        v2l{ rect.right, rect.bottom },
        v2l{ rect.left, rect.bottom },
    };

    for (int i = 0; i < 4; ++i) {
        v2l p = canvas_to_raster(view, corners[i]);
        if (p.x < result.left) {
            result.left = p.x;
        }
        if (p.x > result.right) {
            result.right = p.x;
        }
        if (p.y < result.top) {
            result.top = p.y;
        }
        if (p.y > result.bottom) {
            result.bottom = p.y;
        }
    }

    return result;
}

void
reset_transform_at_origin(v2l* pan_center)
{
    *pan_center = {};
}


// Does point p0 with radius r0 contain point p1 with radius r1?
b32
stroke_point_contains_point(v2l p0, i64 r0, v2l p1, i64 r1)
{
    v2l d = p1 - p0;
    // using manhattan distance, less chance of overflow. Still works well enough for this case.
    u64 m = (u64)MLT_ABS(d.x) + MLT_ABS(d.y) + r1;
    //i32 m = magnitude_i(d) + r1;
    b32 contained = false;
    if ( r0 >= 0 ) {
        contained = (m < (u64)r0);
    } else {
        contained = true;
    }
    return contained;
}

Rect
bounding_box_for_stroke(Stroke* stroke)
{
    Rect bb = bounding_rect_for_points(stroke->points, stroke->num_points);
    Rect bb_enlarged = rect_enlarge(bb, stroke->brush.radius);
    return bb_enlarged;
}

Rect
bounding_box_for_last_n_points(Stroke* stroke, i32 last_n)
{
    i32 forward = max(stroke->num_points - last_n, 0);
    i32 num_points = min(last_n, stroke->num_points);
    Rect bb = bounding_rect_for_points(stroke->points + forward, num_points);
    Rect bb_enlarged = rect_enlarge(bb, stroke->brush.radius);
    return bb_enlarged;
}

Rect
canvas_rect_to_raster_rect(CanvasView* view, Rect canvas_rect)
{
    Rect raster_rect;
    raster_rect.bot_right = canvas_to_raster(view, canvas_rect.bot_right);
    raster_rect.top_left = canvas_to_raster(view, canvas_rect.top_left);
    return raster_rect;
}