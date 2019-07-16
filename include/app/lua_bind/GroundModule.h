#pragma once

#include "useful/useful.h"

namespace app::lua_bind {
    namespace GroundModule {
        u64 attach(u64,int groundTouchFlag) asm("_ZN3app8lua_bind25GroundModule__attach_implEPNS_26BattleObjectModuleAccessorENS_15GroundTouchFlagE") LINKABLE;
        u64 attach_ground(u64,bool) asm("_ZN3app8lua_bind32GroundModule__attach_ground_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 can_entry_cliff(u64) asm("_ZN3app8lua_bind34GroundModule__can_entry_cliff_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 can_entry_cliff_hang_data(u64,u64,int groundCliffCheckKind) asm("_ZN3app8lua_bind44GroundModule__can_entry_cliff_hang_data_implEPNS_26BattleObjectModuleAccessorEjNS_20GroundCliffCheckKindE") LINKABLE;
        u64 center_pos(u64) asm("_ZN3app8lua_bind29GroundModule__center_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 check_down_correct_pos(u64,Vector2f) asm("_ZN3app8lua_bind41GroundModule__check_down_correct_pos_implEPNS_26BattleObjectModuleAccessorEN3phx8Vector2fE") LINKABLE;
        u64 clear_cliff_point(u64) asm("_ZN3app8lua_bind36GroundModule__clear_cliff_point_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 clear_pass_floor(u64) asm("_ZN3app8lua_bind35GroundModule__clear_pass_floor_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 cliff_check(u64) asm("_ZN3app8lua_bind30GroundModule__cliff_check_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 correct(u64,int groundCorrectKind) asm("_ZN3app8lua_bind26GroundModule__correct_implEPNS_26BattleObjectModuleAccessorENS_17GroundCorrectKindE") LINKABLE;
        u64 correct_pos(u64) asm("_ZN3app8lua_bind30GroundModule__correct_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 detach(u64,int) asm("_ZN3app8lua_bind25GroundModule__detach_implEPNS_26BattleObjectModuleAccessorEi") LINKABLE;
        u64 entry_cliff(u64) asm("_ZN3app8lua_bind30GroundModule__entry_cliff_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_center_pos(u64) asm("_ZN3app8lua_bind33GroundModule__get_center_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_circle_radius(u64) asm("_ZN3app8lua_bind36GroundModule__get_circle_radius_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_cliff_movement_speed(u64) asm("_ZN3app8lua_bind43GroundModule__get_cliff_movement_speed_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_correct(u64) asm("_ZN3app8lua_bind30GroundModule__get_correct_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_correct_pos(u64) asm("_ZN3app8lua_bind34GroundModule__get_correct_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_correct_pos_local(u64) asm("_ZN3app8lua_bind40GroundModule__get_correct_pos_local_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_distance_to_floor(u64,const Vector3f*,float,bool) asm("_ZN3app8lua_bind40GroundModule__get_distance_to_floor_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector3fEfb") LINKABLE;
        u64 get_down_correct_edge_pos(u64,Vector2f *,const Vector2f*) asm("_ZN3app8lua_bind44GroundModule__get_down_correct_edge_pos_implEPNS_26BattleObjectModuleAccessorERN3phx8Vector2fERKS4_") LINKABLE;
        u64 get_down_friction(u64) asm("_ZN3app8lua_bind36GroundModule__get_down_friction_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_down_movement_speed(u64) asm("_ZN3app8lua_bind42GroundModule__get_down_movement_speed_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_down_pos(u64) asm("_ZN3app8lua_bind31GroundModule__get_down_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_latest_down_correct_pos(u64) asm("_ZN3app8lua_bind46GroundModule__get_latest_down_correct_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_left_pos(u64) asm("_ZN3app8lua_bind31GroundModule__get_left_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_line_movement_speed(u64,u64) asm("_ZN3app8lua_bind42GroundModule__get_line_movement_speed_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 get_rhombus(u64,bool) asm("_ZN3app8lua_bind30GroundModule__get_rhombus_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 get_right_pos(u64) asm("_ZN3app8lua_bind32GroundModule__get_right_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_shape_kind(u64) asm("_ZN3app8lua_bind33GroundModule__get_shape_kind_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_shape_safe_pos(u64) asm("_ZN3app8lua_bind37GroundModule__get_shape_safe_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_touch_flag(u64) asm("_ZN3app8lua_bind33GroundModule__get_touch_flag_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_touch_line_raw(u64,int groundTouchID) asm("_ZN3app8lua_bind37GroundModule__get_touch_line_raw_implEPNS_26BattleObjectModuleAccessorENS_13GroundTouchIDE") LINKABLE;
        u64 get_touch_material_type(u64,u64) asm("_ZN3app8lua_bind42GroundModule__get_touch_material_type_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 get_touch_moment_flag(u64) asm("_ZN3app8lua_bind40GroundModule__get_touch_moment_flag_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_touch_normal(u64,u64) asm("_ZN3app8lua_bind35GroundModule__get_touch_normal_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 get_touch_normal_consider_gravity(u64,u64) asm("_ZN3app8lua_bind52GroundModule__get_touch_normal_consider_gravity_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 get_touch_normal_x_consider_gravity(u64,u64) asm("_ZN3app8lua_bind54GroundModule__get_touch_normal_x_consider_gravity_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 get_touch_pos(u64,u64) asm("_ZN3app8lua_bind32GroundModule__get_touch_pos_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 get_touch_wall_cliff_pos(u64,u64,Vector2f *) asm("_ZN3app8lua_bind43GroundModule__get_touch_wall_cliff_pos_implEPNS_26BattleObjectModuleAccessorEjRN3phx8Vector2fE") LINKABLE;
        u64 get_up_pos(u64) asm("_ZN3app8lua_bind29GroundModule__get_up_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_width(u64) asm("_ZN3app8lua_bind28GroundModule__get_width_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 get_z(u64) asm("_ZN3app8lua_bind24GroundModule__get_z_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 ground_touch_flag(u64) asm("_ZN3app8lua_bind36GroundModule__ground_touch_flag_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 ground_touch_flag_ex(u64,bool,bool) asm("_ZN3app8lua_bind39GroundModule__ground_touch_flag_ex_implEPNS_26BattleObjectModuleAccessorEbb") LINKABLE;
        u64 hang_can_entry_cliff_dir(u64) asm("_ZN3app8lua_bind43GroundModule__hang_can_entry_cliff_dir_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 hang_can_entry_cliff_pos(u64) asm("_ZN3app8lua_bind43GroundModule__hang_can_entry_cliff_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 hang_cliff_dir(u64) asm("_ZN3app8lua_bind33GroundModule__hang_cliff_dir_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 hang_cliff_pos(u64) asm("_ZN3app8lua_bind33GroundModule__hang_cliff_pos_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        Vector3f* hang_cliff_pos_3f(u64) asm("_ZN3app8lua_bind36GroundModule__hang_cliff_pos_3f_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_attach(u64) asm("_ZN3app8lua_bind28GroundModule__is_attach_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_attach_cliff(u64) asm("_ZN3app8lua_bind34GroundModule__is_attach_cliff_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_attachable(u64,int groundTouchFlag) asm("_ZN3app8lua_bind32GroundModule__is_attachable_implEPNS_26BattleObjectModuleAccessorENS_15GroundTouchFlagE") LINKABLE;
        u64 is_floor_touch_line(u64,u64) asm("_ZN3app8lua_bind38GroundModule__is_floor_touch_line_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 is_floor_vanishing(u64) asm("_ZN3app8lua_bind37GroundModule__is_floor_vanishing_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_miss_foot(u64) asm("_ZN3app8lua_bind31GroundModule__is_miss_foot_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_near_cliff(u64,float,float) asm("_ZN3app8lua_bind32GroundModule__is_near_cliff_implEPNS_26BattleObjectModuleAccessorEff") LINKABLE;
        u64 is_ottotto(u64,float) asm("_ZN3app8lua_bind29GroundModule__is_ottotto_implEPNS_26BattleObjectModuleAccessorEf") LINKABLE;
        u64 is_ottotto_lr(u64,float,float) asm("_ZN3app8lua_bind32GroundModule__is_ottotto_lr_implEPNS_26BattleObjectModuleAccessorEff") LINKABLE;
        u64 is_passable_check(u64) asm("_ZN3app8lua_bind36GroundModule__is_passable_check_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_passable_ground(u64) asm("_ZN3app8lua_bind37GroundModule__is_passable_ground_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_status_cliff(u64) asm("_ZN3app8lua_bind34GroundModule__is_status_cliff_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 is_still_on_floor(u64,float,bool) asm("_ZN3app8lua_bind36GroundModule__is_still_on_floor_implEPNS_26BattleObjectModuleAccessorEfb") LINKABLE;
        u64 is_touch(u64,u64) asm("_ZN3app8lua_bind27GroundModule__is_touch_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 is_wall_touch_line(u64,u64) asm("_ZN3app8lua_bind37GroundModule__is_wall_touch_line_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 leave_cliff(u64) asm("_ZN3app8lua_bind30GroundModule__leave_cliff_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 modify_rhombus(u64,float,float,float) asm("_ZN3app8lua_bind33GroundModule__modify_rhombus_implEPNS_26BattleObjectModuleAccessorEfff") LINKABLE;
        u64 pass_floor(u64) asm("_ZN3app8lua_bind29GroundModule__pass_floor_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 ray_check(u64,const Vector2f*,const Vector2f*,bool) asm("_ZN3app8lua_bind28GroundModule__ray_check_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_b") LINKABLE;
        u64 ray_check_get_line(u64,const Vector2f*,const Vector2f*,bool) asm("_ZN3app8lua_bind37GroundModule__ray_check_get_line_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_b") LINKABLE;
        u64 ray_check_get_line_hit_pos(u64,const Vector2f*,const Vector2f*,Vector2f *,bool) asm("_ZN3app8lua_bind45GroundModule__ray_check_get_line_hit_pos_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_b") LINKABLE;
        u64 ray_check_get_line_hit_pos_ignore_any(u64,const Vector2f*,const Vector2f*,Vector2f *,u64) asm("_ZN3app8lua_bind56GroundModule__ray_check_get_line_hit_pos_ignore_any_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_j") LINKABLE;
        u64 ray_check_get_line_hit_pos_no_culling(u64,const Vector2f*,const Vector2f*,Vector2f *,bool) asm("_ZN3app8lua_bind56GroundModule__ray_check_get_line_hit_pos_no_culling_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_b") LINKABLE;
        u64 ray_check_hit_normal(u64,const Vector2f*,const Vector2f*,Vector2f *,bool) asm("_ZN3app8lua_bind39GroundModule__ray_check_hit_normal_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_b") LINKABLE;
        u64 ray_check_hit_pos(u64,const Vector2f*,const Vector2f*,Vector2f *,bool) asm("_ZN3app8lua_bind36GroundModule__ray_check_hit_pos_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_b") LINKABLE;
        u64 ray_check_hit_pos_normal(u64,const Vector2f*,const Vector2f*,Vector2f *,Vector2f *,bool) asm("_ZN3app8lua_bind43GroundModule__ray_check_hit_pos_normal_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_S7_b") LINKABLE;
        u64 ray_check_hit_pos_normal_no_culling(u64,const Vector2f*,const Vector2f*,Vector2f *,Vector2f *,bool) asm("_ZN3app8lua_bind54GroundModule__ray_check_hit_pos_normal_no_culling_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_S7_b") LINKABLE;
        u64 ray_check_hit_pos_target(u64,const Vector2f*,const Vector2f*,Vector2f *,u64,bool) asm("_ZN3app8lua_bind43GroundModule__ray_check_hit_pos_target_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fES6_RS4_jb") LINKABLE;
        u64 reentry_cliff(u64) asm("_ZN3app8lua_bind32GroundModule__reentry_cliff_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 select_cliff_hangdata(u64,u64) asm("_ZN3app8lua_bind40GroundModule__select_cliff_hangdata_implEPNS_26BattleObjectModuleAccessorEj") LINKABLE;
        u64 set_attach_ground(u64,bool) asm("_ZN3app8lua_bind36GroundModule__set_attach_ground_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_auto_detach(u64,bool) asm("_ZN3app8lua_bind34GroundModule__set_auto_detach_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_cliff_check(u64,int groundCliffCheckKind) asm("_ZN3app8lua_bind34GroundModule__set_cliff_check_implEPNS_26BattleObjectModuleAccessorENS_20GroundCliffCheckKindE") LINKABLE;
        u64 set_cloud_through(u64,bool) asm("_ZN3app8lua_bind36GroundModule__set_cloud_through_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_coll_stop_slidable_length(u64,float) asm("_ZN3app8lua_bind48GroundModule__set_coll_stop_slidable_length_implEPNS_26BattleObjectModuleAccessorEf") LINKABLE;
        u64 set_collidable(u64,bool) asm("_ZN3app8lua_bind33GroundModule__set_collidable_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_correct(u64,int groundCorrectKind) asm("_ZN3app8lua_bind30GroundModule__set_correct_implEPNS_26BattleObjectModuleAccessorENS_17GroundCorrectKindE") LINKABLE;
        u64 set_correct_ignore_slope(u64,bool) asm("_ZN3app8lua_bind43GroundModule__set_correct_ignore_slope_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_ignore_boss(u64,bool) asm("_ZN3app8lua_bind34GroundModule__set_ignore_boss_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_ignore_slide_up(u64,bool) asm("_ZN3app8lua_bind38GroundModule__set_ignore_slide_up_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_init_circle(u64,const Vector2f*,float) asm("_ZN3app8lua_bind34GroundModule__set_init_circle_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fEf") LINKABLE;
        u64 set_init_shape_kind(u64) asm("_ZN3app8lua_bind38GroundModule__set_init_shape_kind_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 set_keep_distant_cliff(u64,bool) asm("_ZN3app8lua_bind41GroundModule__set_keep_distant_cliff_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_no_cliff_stop_energy(u64,int) asm("_ZN3app8lua_bind43GroundModule__set_no_cliff_stop_energy_implEPNS_26BattleObjectModuleAccessorEi") LINKABLE;
        u64 set_offset_x(u64,float) asm("_ZN3app8lua_bind31GroundModule__set_offset_x_implEPNS_26BattleObjectModuleAccessorEf") LINKABLE;
        u64 set_offset_y(u64,float) asm("_ZN3app8lua_bind31GroundModule__set_offset_y_implEPNS_26BattleObjectModuleAccessorEf") LINKABLE;
        u64 set_passable_check(u64,bool) asm("_ZN3app8lua_bind37GroundModule__set_passable_check_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_reverse_direction(u64,bool,bool) asm("_ZN3app8lua_bind40GroundModule__set_reverse_direction_implEPNS_26BattleObjectModuleAccessorEbb") LINKABLE;
        u64 set_rhombus_offset(u64,const Vector2f*) asm("_ZN3app8lua_bind37GroundModule__set_rhombus_offset_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fE") LINKABLE;
        u64 set_shape_data_rhombus_modify_node_offset(u64,u64,const Vector3f*) asm("_ZN3app8lua_bind60GroundModule__set_shape_data_rhombus_modify_node_offset_implEPNS_26BattleObjectModuleAccessorEN3phx6Hash40ERKNS3_8Vector3fE") LINKABLE;
        u64 set_shape_flag(u64,u16,bool) asm("_ZN3app8lua_bind33GroundModule__set_shape_flag_implEPNS_26BattleObjectModuleAccessorEtb") LINKABLE;
        u64 set_shape_kind(u64,int groundCorrectShapeType) asm("_ZN3app8lua_bind33GroundModule__set_shape_kind_implEPNS_26BattleObjectModuleAccessorENS_5grcol22GroundCorrectShapeTypeE") LINKABLE;
        u64 set_shape_safe_pos(u64,const Vector2f*) asm("_ZN3app8lua_bind37GroundModule__set_shape_safe_pos_implEPNS_26BattleObjectModuleAccessorERKN3phx8Vector2fE") LINKABLE;
        u64 set_status_ground(u64) asm("_ZN3app8lua_bind36GroundModule__set_status_ground_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 set_test_coll_stop(u64,bool) asm("_ZN3app8lua_bind37GroundModule__set_test_coll_stop_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_test_coll_stop_status(u64,bool) asm("_ZN3app8lua_bind44GroundModule__set_test_coll_stop_status_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_update_shape(u64,bool) asm("_ZN3app8lua_bind35GroundModule__set_update_shape_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
        u64 set_z(u64,float) asm("_ZN3app8lua_bind24GroundModule__set_z_implEPNS_26BattleObjectModuleAccessorEf") LINKABLE;
        u64 test(u64) asm("_ZN3app8lua_bind23GroundModule__test_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 test_ground(u64) asm("_ZN3app8lua_bind30GroundModule__test_ground_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 update_force(u64) asm("_ZN3app8lua_bind31GroundModule__update_force_implEPNS_26BattleObjectModuleAccessorE") LINKABLE;
        u64 update_shape(u64,bool) asm("_ZN3app8lua_bind31GroundModule__update_shape_implEPNS_26BattleObjectModuleAccessorEb") LINKABLE;
    }
}