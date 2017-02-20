//
// Created by Massimiliano Pesce on 05/02/17.
//

#pragma once

#include <fstream>
#include <SDL_rect.h>
#include <third_parties/json.hpp>

namespace Utils {

    inline nlohmann::json jsonFromFile(std::string file_path) {
        std::ifstream file_stream(file_path, std::ios::in);

        if (!file_stream) {
            return nullptr;
        }

        std::string file_content((std::istreambuf_iterator<char>(file_stream)), std::istreambuf_iterator<char>());
        return nlohmann::json::parse(file_content.c_str());
    }

    inline SDL_Rect rectFromJson(nlohmann::json json_rect) {
        SDL_Rect r;
        r.x = json_rect["x"];
        r.y = json_rect["y"];
        r.w = json_rect["width"];
        r.h = json_rect["height"];
        return r;
    }

    inline bool boolFromJsonField(nlohmann::json json_object, std::string field_key, bool default_value) {
        if (json_object.find(field_key) != json_object.end()) {
            return bool(json_object[field_key]);
        } else {
            return default_value;
        }
    }

    inline int intFromJsonField(nlohmann::json json_object, std::string field_key, int default_value) {
        if (json_object.find(field_key) != json_object.end()) {
            return json_object[field_key];
        } else {
            return default_value;
        }
    }

    inline std::vector<SDL_Point> bresenhamSteps(int x0, int y0, int x1, int y1) {
        std::vector<SDL_Point> steps;

        int delta_x = abs(x1 - x0);
        int delta_y = abs(y1 - y0);
        int step_x = x0 < x1 ? 1 : -1;
        int step_y = y0 < y1 ? 1 : -1;
        int error = (delta_x > delta_y ? delta_x : -delta_y) / 2, e2;

        for (;;) {
            steps.push_back({x0, y0});
            if (x0 == x1 && y0 == y1) {
                break;
            }
            e2 = error;
            if (e2 > -delta_x) {
                error -= delta_y;
                x0 += step_x;
            }
            if (e2 < delta_y) {
                error += delta_x;
                y0 += step_y;
            }
        }

        return steps;
    }

    inline void bresenhamSteps(int x0, int y0, int x1, int y1, std::function<void (int,int)> func) {
        int delta_x = abs(x1 - x0);
        int delta_y = abs(y1 - y0);
        int step_x = x0 < x1 ? 1 : -1;
        int step_y = y0 < y1 ? 1 : -1;
        int error = (delta_x > delta_y ? delta_x : -delta_y) / 2, e2;

        for (;;) {
            func(x0, y0);
            if (x0 == x1 && y0 == y1) {
                break;
            }
            e2 = error;
            if (e2 > -delta_x) {
                error -= delta_y;
                x0 += step_x;
            }
            if (e2 < delta_y) {
                error += delta_x;
                y0 += step_y;
            }
        }
    }
}