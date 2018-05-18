
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include "Wrapper.h"
#include "Season.h"
#include "Example.h"
#include "winsock.h"
#include "windows.h"
#include "mysql.h"
template <int i=44>
class fibo{
    static long long fib(int a)  {
        if (a == 1 || a == 2) {
            return 1;
        } else if (a == 3) {
            return 2;
        } else {
            return fib(a - 1) + fib(a - 2);
        }
    }
public:
    long long operator()(){
        return fib(i);
    }

};


MYSQL mysql; //mysql连接
MYSQL_FIELD *fd;  //字段列数组
char field[32][32];  //存字段名二维数组
MYSQL_RES *res; //这个结构代表返回行的一个查询结果集
MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
std::string query; //查询语句

bool ConnectDatabase();     //函数声明
void FreeConnect();
bool QueryDatabase1();  //查询1
bool QueryDatabase2();  //查询2
bool InsertData();
bool ModifyData();
bool DeleteData();
int main() {
    ConnectDatabase();
    QueryDatabase1();
    InsertData();
    QueryDatabase2();
    ModifyData();
    QueryDatabase2();
    DeleteData();
    QueryDatabase2();
    FreeConnect();
    system("pause");
    return 0;
}

bool ConnectDatabase()
{

    //初始化mysql
    mysql_init(&mysql);  //连接mysql，数据库

    //返回false则连接失败，返回true则连接成功
    if (mysql_real_connect(&mysql,"localhost", "cbaas", "cbaas", "cbaas",0,nullptr,0)) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
    {
        std::cout << "Connected...\n";
        return true;
    }else{
        std::cout << "Error connecting to database:" << mysql_error(&mysql)  << std::endl;
        return false;
    }
}
//释放资源
void FreeConnect()
{
    //释放资源
    mysql_free_result(res);
    mysql_close(&mysql);
}
/***************************数据库操作***********************************/
//其实所有的数据库操作都是先写个sql语句，然后用mysql_query(&mysql,query)来完成，包括创建数据库或表，增删改查
bool QueryDatabase1()
{
    query="select f.fund_name,f.inception_date,f.id,f.stage_key,f.prime_broker from fund f where f.valid=1 and f.asset_class=10 limit 12"; //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
    mysql_query(&mysql,"set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
    //返回0 查询成功，返回1查询失败
    if(mysql_query(&mysql, query.c_str()))        //执行SQL语句
    {
        std::cout<<"Query failed: " << mysql_error(&mysql)  << std::endl;
        return false;
    }
    else
    {
         std::cout << "query success\n";
    }
    //获取结果集
    if (!(res=mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
    {
        std::cout << "Couldn't get result from " << mysql_error(&mysql) << std::endl;
        return false;
    }

    //打印数据行数
    std::cout << "number of dataline returned:"<<mysql_affected_rows(&mysql) << std::endl;

    enum CNM:unsigned char{RECORD_COUNT=5};
    //获取字段的信息
    std::vector<std::string> str_field;  //定义一个字符串数组存储字段信息
    for(int i=0;i<RECORD_COUNT;i++)   //在已知字段数量的情况下获取字段名
    {
        str_field.emplace_back(mysql_fetch_field(res)->name);
    }
    for(std::string colName:str_field)   //打印字段
        std::cout << colName << "\t";
        std::cout <<std::endl;
    //打印获取的数据
    while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
    {
        for(int i=0;i<RECORD_COUNT;i++)
        {
            std::cout << (column[i] ? column[i]:"null") << "\t";
        }
       std::cout << std::endl;
    }
    return true;
}
bool QueryDatabase2()
{
    mysql_query(&mysql,"set names gbk");
    //返回0 查询成功，返回1查询失败
    if(mysql_query(&mysql, "select * from app_user"))        //执行SQL语句
    {
         std::cout << "Query failed "<<mysql_error(&mysql) << std::endl;
        return false;
    }
    else
    {
        std::cout << "query success"  << std::endl;
    }
    res=mysql_store_result(&mysql);
    //打印数据行数
    std::cout << "number of dataline returned:"<< mysql_affected_rows(&mysql);
    for(int i=0;fd=mysql_fetch_field(res);i++)  //获取字段名
        strcpy(field[i],fd->name);
    int j=mysql_num_fields(res);  // 获取列数
    for(int i=0;i<j;i++)  //打印字段
        std::cout << field[i]  << "\t";
     std::cout << std::endl;
    while(column=mysql_fetch_row(res))
    {
        for(int i=0;i<j;i++)
            std::cout << column[i]<<"\t";
        std::cout << std::endl;

    }
    return true;
}
//插入数据
bool InsertData()
{
    query="insert into user values (NULL, 'Lilei', 'wyt2588zs','lilei23@sina.cn');";  //可以想办法实现手动在控制台手动输入指令
    if(mysql_query(&mysql, query.c_str()))        //执行SQL语句
    {
        std::cout << "Query failed "<<mysql_error(&mysql) << std::endl;
        return false;
    }
    else
    {
        std::cout << "Insert success\n";
        return true;
    }
}
//修改数据
bool ModifyData()
{
    query="update user set email='lilei325@163.com' where name='Lilei'";
    if(mysql_query(&mysql, query.c_str()))        //执行SQL语句
    {
        std::cout << "Query failed :"<<mysql_error(&mysql) << std::endl;
        return false;
    }
    else
    {
        std::cout <<"Insert success\n";
        return true;
    }
}
//删除数据
bool DeleteData()
{
    /*sprintf(query, "delete from user where id=6");*/
    char query[100];
    std::cout <<"please input the sql:\n";
    std::cin>>query;  //这里手动输入sql语句
    if(mysql_query(&mysql, query))        //执行SQL语句
    {
        std::cout <<"Query failed :"<<mysql_error(&mysql) << std::endl;
        return false;
    }
    else
    {
        std::cout <<"Insert success\n";
        return true;
    }
}

















int main2() {
    fibo<> f;
}

template<typename T=Example,int b=23>
void polymophis(const T& ob=Example{}) {
    ob.someFunc();
}
template <typename T=Example,int t=989>
class Dumping{
    T inst;
    public:Dumping(){
         std::cout << t  << std::endl;
    }
};
int main3() {
    Dumping<> dumping;
     Example ex1{};
    polymophis();
}

int main1() {
    Wrapper wrapper;
    wrapper.getWeight(Wrapper::ac::AIE);
//     std::cout << AbstractBase::a1 << std::endl;
    std::cout << sizeof(Wrapper::ac::CIE) << std::endl;
    std::cout << Season::SPRING.getString() << std::endl;
}