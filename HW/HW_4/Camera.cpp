#include "Camera.h"

// TODO: fill up the following function properly 
void Camera::set_rotation(const glm::quat& _q)
{
  front_dir_ = glm::normalize(glm::mat4_cast(_q) * glm::vec4(0.0f, 0.0f, -1.0f, 0.0f));
  up_dir_ = glm::normalize(glm::mat4_cast(_q) * glm::vec4(0.0f, 1.0f, 0.0f, 0.0f));
  right_dir_ = glm::normalize(glm::cross(front_dir_, up_dir_));
}

// TODO: re-write the following function properly 
const glm::quat Camera::get_rotation() const
{
  glm::mat3 rotation_matrix = glm::mat3(right_dir_, up_dir_, -front_dir_);
  return glm::quat_cast(rotation_matrix);
}

// TODO: fill up the following function properly 
void Camera::set_pose(const glm::quat& _q, const glm::vec3& _t)
{
  set_rotation(_q);
  position_ = _t;
}

// TODO: fill up the following function properly 
void Camera::get_pose(glm::quat& _q, glm::vec3& _t) const
{
  _q = get_rotation();
  _t = position_;
}

// TODO: rewrite the following function properly 
const glm::mat4 Camera::get_pose() const
{
  return glm::translate(glm::mat4(1.0f), position_);
}

// TODO: fill up the following function properly 
void Camera::set_pose(const glm::mat4& _frame)
{
  right_dir_ = _frame[0];
  up_dir_ = _frame[1];
  front_dir_ = _frame[2];
  position_ = _frame[3];
}

// TODO: fill up the following function properly 
void Camera::set_pose(const glm::vec3& _pos, const glm::vec3& _at, const glm::vec3& _up_dir)
{
  glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f);
  front_dir_ = glm::normalize( _pos - _at); 
  right_dir_ = glm::normalize(glm::cross(world_up, front_dir_));
  up_dir_ = glm::normalize(glm::cross(front_dir_, right_dir_));
  position_ = _pos;
}

// TODO: rewrite the following function properly 
const glm::mat4 Camera::get_view_matrix() const
{
  return glm::lookAt(position_, position_ + front_dir_, up_dir_);
}

// TODO: rewrite the following function properly 
const glm::mat4 Camera::get_projection_matrix() const
{
  if (mode_ == kPerspective)
    return glm::perspective(glm::radians(fovy_), aspect_, near_, far_);
  else
  {
      float ortho_left = -ortho_scale_ * aspect_ / 2.0f;
      float ortho_right = ortho_scale_ * aspect_ / 2.0f;
      float ortho_bottom = -ortho_scale_ / 2.0f;
      float ortho_top = ortho_scale_ / 2.0f;
      return glm::ortho(ortho_left, ortho_right, ortho_bottom, ortho_top, near_, far_);
  }
}

// TODO: fill up the following functions properly 
void Camera::move_forward(float delta)
{
  position_ += front_dir_ * delta;
}

// TODO: fill up the following functions properly 
void Camera::move_backward(float delta)
{
  position_ -= delta * front_dir_;
}

// TODO: fill up the following functions properly 
void Camera::move_left(float delta)
{
  position_ -= delta * right_dir_;
}

// TODO: fill up the following functions properly 
void Camera::move_right(float delta)
{
  
  position_ += delta * right_dir_;
}

// TODO: fill up the following functions properly 
void Camera::move_up(float delta)
{
  position_ += delta * up_dir_;
}

// TODO: fill up the following functions properly 
void Camera::move_down(float delta)
{
  position_ -= delta * up_dir_;
}
