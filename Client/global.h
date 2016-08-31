#ifndef GLOBAL_H
#define GLOBAL_H
#include<QDataStream>
const QDataStream::Version VERSION=QDataStream::Qt_4_6; //QDataStreamʹ�õİ汾
typedef quint16 MessageSize;    //���ݰ���С
namespace MessageType{
    enum MessageType{
    GetServer=0x0031,
    Login=0x0041,       //��Ϣ���¼�й�
    Register=0x0042,    //��Ϣ��ע���й�
    UserList=0x0043,
    UserStatusUpdate=0x0044,
    InvalidMessage=0x0051,   //�����δ���յ���Ч������ʱ�����������־���ͻ���
    Message=0x0061,
    ParticipantLeft=0x0062,
    FileName=0x0063,
    Refuse=0x0064,
    NewParticipant=0x0065
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
\*---------------------------���ô�С-------------------*/
//�˿ںţ� tcp 6666  ;  udp 25252  ;  ˽��udp 25253   ;   Ⱥ��udp 25254
#endif // GLOBAL_H
