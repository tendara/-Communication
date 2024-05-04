#include "rclcpp/rclcpp.hpp"
//include string 
#include "std_msgs/msg/string.hpp"
//include 
#include "std_msgs/msg/u_int32.hpp"
//#include "village_interfaces/srv/sell_novel.hpp"
//#include <queue>
//zhanwei
using std::placeholders::_1;
using std::placeholders::_1;
class singleDogNode:public rclcpp::Node
{
private:
    //create subscription
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_novel;
    rclcpp::Publisher<std_msgs::msg::UInt32>::SharedPtr pub_money;
  
    //声明回调组
    //rclcpp::CallbackGroup::SharedPtr sell_novels_callback_group

    //2.create callback
   void novel_callback(const std_msgs::msg::String::SharedPtr novels)
    {
        std_msgs::msg::UInt32 money;
        money.data = 10;
        pub_money->publish(money);
        RCLCPP_INFO(this->get_logger(),"read%s",novels->data.c_str());
    }
    //void sell_novel_callback(const village_interfaces::srv::)
public:
   singleDogNode(std::string name):Node(name)
{
 RCLCPP_INFO(this->get_logger(),"danshengou%s",name.c_str());
 //create subscription
 sub_novel = this->create_subscription<std_msgs::msg::String>("sexy_girl",10,std::bind(&singleDogNode::novel_callback,this,_1));
 pub_money = this->create_publisher<std_msgs::msg::UInt32>("sexy_girl_money",10);
}
   
};




int main(int argc,char ** argv)
{
    rclcpp::init(argc,argv);
    auto node =std::make_shared<singleDogNode>("wang2");
    
    RCLCPP_INFO(node->get_logger(),"wang2");
    rclcpp::spin(node);
    rclcpp::shutdown();
}