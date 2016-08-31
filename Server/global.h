#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include<QDataStream>
const QDataStream::Version VERSION=QDataStream::Qt_4_6; //QDataStream使用的版本
typedef quint16 MessageSize;    //数据包大小
namespace MessageType{
    enum MessageType{
    GetServer=0x0031,   //获取服务器主机地址
    Login=0x0041,       //登录相关
    Register=0x0042,    //注册相关
    UserList=0x0043,    //传输用户列表相关
    UserStatusUpdate=0x0044,    //更新用户状态
    InvalidMessage=0x0051   //服务端未接收到有效的数据时，返回这个标志给客户端
};
}
/*----------------------数据包格式----------------------*\
|QDataStream out(&buffer, QIODevice::WriteOnly)--------|
|out.setVersion(VERSION)-----设置版本--------------------|
|out<<(MessageSize)0---------预留空间--------------------|
|out<<MessageType::Login-----消息类型--------------------|
|out<<.....---------------要传送的数据--------------------|
|out.device()->seek(0)----回到预留空间--------------------|
|out<<(MessageType)(buffer.size()-sizeof(MessageType))--|
|----------------------------设置大小--------------------|
\*------------端口号:tcp 6666 ; udp 25252---------------*/
#endif // GLOBAL_H
