#pragma once
/*
	1.ʲô��c++?
	c++���ص㣺��װ���̳С���̬��
	c++֧�ֵı��ģʽ����������̡�������̱�̡����ͱ�̣�STL,�㷨�������ֿ���
	���ض�ĳһ���������͵�һ�㻯��̷�ʽ��
	���ƣ���Ч�ʸ�

	2.ʲô��������󣿣�OOP��
	����ʵ�������⡢�����һ�ַ�����˼�롣
	������Ҫ��ת���ɶ�����д�����˼�롣

	3.ʲô�����ģʽ��������
	�����Ƿ���ʹ�õı�̷�ʽ���ܽᡣ
	eg:����ģʽ������ģʽ

	4.const������
	const���α��������������޸�
	const���κ����������޸����ڳ�Ա
	const���ζ���const���ɵ����أ���const����ֻ�ܵ���const��������const������Ե���const����

	5.static����ʲôʱ���ʼ����
	���е�static����ֻ�ڳ�������ʱ��ʼ��һ��
	������static����ֻ��ʼ��һ��

	6.��ջ�����𣿶�ջ���������ڣ�
	�ѣ�����ϵͳ���������棬�ٶ�������һ���ɳ���Ա������ͷţ�δ���յ��ɲ���ϵͳ����
	ջ������ϵͳ��һ�����棬�ٶȿ죩��һ��������žֲ������ͺ������������������ͷţ�
	�÷������ݽṹ��ջ�Ƚ���

	�ѣ����ݽṹ�������Կ���һ������������
	ջ�����ݽṹ��������ȳ�

	7.��װ���̳кͶ�̬��
	----------------------------------------------------------
	��װ�������������Էŵ�һ������
		  ��ֹ�����������б��ƻ�
	�̳У��������ã���ʡʱ��
	��̬������ָ��ָ������ʵ��
		  ������ͬ�ķ�����������ͬ�Ľ��

	8.���ú�ָ�������
	���ã��Ǳ����ı���������Ϊ��
		  ���÷����ڴ�
	ָ�룺��һ��������ָ������ĵ�ַ������Ϊ��
		  ��Ҫ�����ڴ�

	9.ʲô���ڴ�й©��һ�����һֱ���еĳ���Ӱ��ܴ󣬶�������һ������˳���
	����Ӱ���С����
	�����ڴ�й©��ָ��Խ�磬����ʲô������
	��α����ڴ�й©��
	�ڴ�й©��new/malloc�Ķ�����ʹ�����֮��û���ͷţ�һֱռ�����ڴ�
	���⣺new/delete�ɶԳ��֣�malloc/free�ɶԳ��֣�
	�쳣����ʱע��new/delete�����
		
	10.���õ������㷨����Щ����ȱ����ʲô��
	ѡ��(һ�����ò���������)��ð�ݡ����١��鲢�������򡢲�������
	
	��������ð�������һ�ָĽ�
		�ŵ㣺�����ƶ���
		ȱ�㣺�ȶ��Բ���
	�鲢���򣺷��η������ȶ��������㷨��һ��������������򣬵��ֲ�����
		�ŵ㣺Ч�ʸ�O(n)���ȶ�
		ȱ�㣺�Ƚ�ռ���ڴ�

	11.new��malloc����ͬ��
	ͬ���������ڴ�Ķ�̬����
	�죺��1��new��c++���������malloc��c�ĺ���
		��2��malloc���ܴ����Զ������͵Ĺ��캯����new�ſ���
		��3��new����=malloc+���캯��

	12.TCP��UDP������ʲô��IOCP?
	TCP���������ӵĿɿ����䣬����Ļ�����λ�����ݰ�����������
	UDP�������ӵķǿɿ����䣬����Ч�ʸߣ�����Ļ�����λ�����ݱ���

	IOCP:IO completion port(IO��ɶ˿�)���첽IO��API,���Ը�Ч�İ��¼�֪ͨ��Ӧ�ò�
	�������첽��ʽ��ͬ���ǣ����׽��֡�socket������ɶ˿�����������Ȼ��Ϳ��Խ���
	������winsockͨѶ�ˡ���һ���¼�������ʱ�򣬴���ɶ˿ھͻᱻ����ϵͳ�ŵ�һ����Ϣ
	�����У�Ӧ�ó���ͨ����ѯ�Ϳ��Բ鵽����¼���

	13.ͬ�����첽������
	ͬ�����ڷ���һ������֮����û�еõ����֮ǰ���Ͳ��᷵�ء�
	�첽����һ���������ú󣬲��õȴ�����������ɱ�������ͨ��״̬����Ϣ��֪ͨ
	�����߻���ʹ�ûص������á�

	14.c++�ľ�̬�����;�̬������
	static��Ա�����ڱ���ʱ��ʼ����������洢��ֻ�������ʼ����
	��̬���������������ɶԾ�̬�����ķ�װ��������
	��̬����ֻ�ܷ��ʾ�̬������ԭ�򣺾�̬���������࣬û��thisָ�룬���Ǿ�̬����
	���ڶ��󡣷Ǿ�̬������thisָ��ᱻ�����������롣

	15.˵һ������ڴ���˽⡣
	
*/