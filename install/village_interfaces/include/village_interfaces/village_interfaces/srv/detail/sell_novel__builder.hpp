// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from village_interfaces:srv/SellNovel.idl
// generated code does not contain a copyright notice

#ifndef VILLAGE_INTERFACES__SRV__DETAIL__SELL_NOVEL__BUILDER_HPP_
#define VILLAGE_INTERFACES__SRV__DETAIL__SELL_NOVEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "village_interfaces/srv/detail/sell_novel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace village_interfaces
{

namespace srv
{

namespace builder
{

class Init_SellNovel_Request_money
{
public:
  Init_SellNovel_Request_money()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::village_interfaces::srv::SellNovel_Request money(::village_interfaces::srv::SellNovel_Request::_money_type arg)
  {
    msg_.money = std::move(arg);
    return std::move(msg_);
  }

private:
  ::village_interfaces::srv::SellNovel_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::village_interfaces::srv::SellNovel_Request>()
{
  return village_interfaces::srv::builder::Init_SellNovel_Request_money();
}

}  // namespace village_interfaces


namespace village_interfaces
{

namespace srv
{

namespace builder
{

class Init_SellNovel_Response_novel
{
public:
  Init_SellNovel_Response_novel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::village_interfaces::srv::SellNovel_Response novel(::village_interfaces::srv::SellNovel_Response::_novel_type arg)
  {
    msg_.novel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::village_interfaces::srv::SellNovel_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::village_interfaces::srv::SellNovel_Response>()
{
  return village_interfaces::srv::builder::Init_SellNovel_Response_novel();
}

}  // namespace village_interfaces

#endif  // VILLAGE_INTERFACES__SRV__DETAIL__SELL_NOVEL__BUILDER_HPP_
