#ifndef _FAAC_ENCODER_H_
#define _FAAC_ENCODER_H_

#include "faac.h"

class FAACEncoder
{
public:
    FAACEncoder();

    ~FAACEncoder();

    /*
    ��ʼ��
    @param samRate ������ 
    @param channels ͨ����
    @param bitsPerSample ����λ����һ����16(16λUSHORT)
    @return void 
    */
    void Init(unsigned int samRate, unsigned int channels, int bitsPerSample);

    /*
    FAAC���뺯��
    @param inputBuf ���뻺���� 
    @param samCount �����������InputSamples
    @param outBuf ���������������С���MaxOutBytes
    @param bufSize [out] ��������Ĵ�С
    @return void 
    */
    void Encode(unsigned char* inputBuf, unsigned int samCount, unsigned char* outBuf, unsigned int& bufSize);
	/*
	��Init����䣬��ʾÿ�α���÷���Ĳ�����(samCount)
	*/
    unsigned long InputSamples() { return input_sams_; }
	/*
	��Init����䣬��ʾ���뻺����������С(bufSize��ʼֵ)
	*/
    unsigned long MaxOutBytes() { return max_output_bytes_; }
	/// �ͷź���
    void Destroy();

private:
    faacEncHandle faac_handle_;
    unsigned long input_sams_;
    unsigned long max_output_bytes_;
};

#endif // _FAAC_ENCODER_H_
