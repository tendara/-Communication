import rclpy
from rclpy.node import Node
from std_msgs.msg import String
#导入服务接口
from village_interfaces.srv import BorrowMoney
class BaiPiaoNode(Node):
    """
    创建一个李三节点，并在初始化时输出一个话
    """
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("大家好，我是李三，李四他哥，我可以白嫖李四的小说！")
        self.sub_ = self.create_subscription(String,"sexy_girl",self.recv_callback,10)
        #声明并创建客户端
        self.borrow_client = self.create_client(BorrowMoney,"borrow_money")

    def recv_callback(self,novel):
        self.get_logger().info('李三：我已经收到了：%s' % novel.data)
        #调用客户端发送请求
    def borrow_money_eat(self,money=10):
        self.get_logger().info("借钱了，请求借钱%d"%money)
        #确认请求是否在线
        while not self.borrow_client.wait_for_service(1.0):
            self.get_logger().warn("服务不在线")
        #构造请求内容
        request = BorrowMoney.Request()
        request.name = self.get_name()
        request.money = money
        #发送异步借钱请求
        self.borrow_client.call_async(request).add_done_callback(self.borrow_response_callback)
    #创建请求结果的回调函数
    def borrow_response_callback(self,response):
        result = response.result()
        if result.success:
            self.get_logger().info("%d"%result.money)
        else:
            self.get_logger().info("失败")

def main(args=None):
    """
    ros2运行该节点的入口函数，可配置函数名称
    """
    rclpy.init(args=args) # 初始化rclpy
    node = BaiPiaoNode("li3")  # 新建一个节点
    node.borrow_money_eat()#调用借钱服务
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # rcl关闭