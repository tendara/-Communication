import rclpy
from rclpy.node import Node
#1.import type
from std_msgs.msg import String,UInt32
#导入服务端接口
from village_interfaces.srv import BorrowMoney
class WriterNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("nihao%s" % name)
        #2.create publisher
        self.pub_novel = self.create_publisher(String,"sexy_girl",10)
        #self.pub_novel.publish()
        self.count = 0
        self.timer_period = 5
        self.timer = self.create_timer(self.timer_period,self.timer_callback)
        self.account = 80
        self.sub_money = self.create_subscription(UInt32,"sexy_girl_money",self.recv_money_callback,10)
        self.borrow_server = self.create_service(BorrowMoney,"borrow_money",self.borrow_money_callback)
    #创建服务端回调函数
    def borrow_money_callback(self,request,response):#request客户端请求数据，response服务端响应
        self.get_logger().info("受到来自%s的借钱请求，账户目前有%d"% (request.name,self.account))
        if request.money <=self.account/10 :
            response.success = True
            response.money = request.money
            self.account -= request.money
            self.get_logger().info("借钱成功，借出%d,目前还剩%d"%(request.money,self.account))
        else:
            response.success = False
            response.money = 0
            self.get_logger().info("不借")
        return response

    def timer_callback(self):
        msg = String()
        msg.data = "%dturn,%dtime"%(self.count,self.count)
        self.pub_novel.publish(msg) #publish
        self.get_logger().info("publish one artic,%s"%msg.data)
        self.count +=1

    def recv_money_callback(self,money):
        self.account +=money.data
        self.get_logger().info("%dinput,%dall"%(money.data,self.account))
def main(args=None):
   
    rclpy.init(args=args)
    li4_node = WriterNode("li4")
    rclpy.spin(li4_node)
    rclpy.shutdown()