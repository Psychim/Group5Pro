#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include<QDataStream>
const QDataStream::Version VERSION=QDataStream::Qt_4_6; //QDataStreamʹ�õİ汾
typedef quint16 MessageSize;    //���ݰ���С
namespace MessageType{
    enum MessageType{
    GetServer=0x0031,   //��ȡ������������ַ
    Login=0x0041,       //��¼���
    Register=0x0042,    //ע�����
    UserList=0x0043,    //�����û��б����
    UserStatusUpdate=0x0044,    //�����û�״̬
    InvalidMessage=0x0051   //�����δ���յ���Ч������ʱ�����������־���ͻ���
};
}
/*----------------------���ݰ���ʽ----------------------*\
|QDataStream out(&buffer, QIODevice::WriteOnly)--------|
|out.setVersion(VERSION)-----���ð汾--------------------|
|out<<(MessageSize)0---------Ԥ���ռ�--------------------|
|out<<MessageType::Login-----��Ϣ����--------------------|
|out<<.....---------------Ҫ���͵�����--------------------|
|out.device()->seek(0)----�ص�Ԥ���ռ�--------------------|
|out<<(MessageType)(buffer.size()-sizeof(MessageType))--|
|----------------------------���ô�С--------------------|
\*------------�˿ں�:tcp 6666 ; udp 25252---------------*/
#endif // GLOBAL_H
