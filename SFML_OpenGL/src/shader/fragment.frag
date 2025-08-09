#version 410 core
precision highp float;
uniform int u_mode_f;
uniform sampler2D u_texture;
uniform vec2 p_texcoord;

uniform vec4 u_color;
out vec4 o_color;

void main() {
    if (u_mode_f == 0) {
        o_color = u_color;
    } else {
        o_color = texture(u_texture, p_texcoord);
    }
}