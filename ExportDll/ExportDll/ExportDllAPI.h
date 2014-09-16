#ifndef AFXSTD_860013BE_C31D_4099_9995_6573EC72878A
#define AFXSTD_860013BE_C31D_4099_9995_6573EC72878A

#if _MSC_VER >= 1200
#pragma once
#endif //_MSC_VER >= 1200

#ifndef EXPORTDLL_EXPORTS
	#define EXPORTDLL_API extern "C" _declspec(dllimport)
#else
	#define EXPORTDLL_API extern "C" _declspec(dllexport)
#endif//!EXPORTDLL_EXPORTS


/************************************************************************/
/*                          1. ����Լ��                                   */
/************************************************************************/
//1.1 ��׼����Լ��
EXPORTDLL_API void _stdcall CallingCvt_Stdcall();

//1.2 C����Լ��
EXPORTDLL_API void _cdecl   CallingCvt_Cdecl();


/************************************************************************/
/*                          2. ����ָ��                                   */
/************************************************************************/
//2.1 ��ȡ�ص������ĺ�����ַ
typedef int (*PCALLBACKFUN)(int i);
int PrintInt(int i);
EXPORTDLL_API PCALLBACKFUN CallBack_GetFunPtr();


/************************************************************************/
/*                          3. �ַ���                                    */
/************************************************************************/
//3.1 �ַ�����Ϊ�������
EXPORTDLL_API int Str_Output(WCHAR *pStr);

//3.2 �ַ�����Ϊ����,��Ҫ�����޸ķ���
EXPORTDLL_API int Str_Change(WCHAR *pStr, int len);

//3.3 �ַ�����Ϊ����ֵ
static  WCHAR *g_StrReturn = L"Str_Return";
EXPORTDLL_API WCHAR * Str_Return();

//3.4 �ַ���������Ϊ����,ÿ��Ԫ�س���Ϊ10
EXPORTDLL_API int Str_ChangeArr(WCHAR **ppStr, int len);

//3.5 �ͷŷ��йܵ��ڴ�,128
EXPORTDLL_API void Str_ParameterOut(WCHAR **ppStr);


/************************************************************************/
/*                          4. �ṹ��                                    */
/************************************************************************/
//4.1 �ṹ����Ϊ�����������
typedef struct _testStru1
{
	int		iVal;
	char	cVal;
	__int64 llVal;
}testStru1;
EXPORTDLL_API  void Struct_Change(testStru1 *pStru);

//4.2 �ṹ��߽����
#pragma pack(1)
typedef struct _testStru2
{
	int		iVal;
	char	cVal;
	__int64 llVal;
}testStru2;
#pragma pack()
EXPORTDLL_API  void Struct_PackN(testStru2 *pStru);

//4.3 �ṹ���к��������������͵�����
typedef struct _testStru3
{
	int		iValArrp[30];
	WCHAR	szChArr[30];
}testStru3;
EXPORTDLL_API  void Struct_ChangeArr(testStru3 *pStru);

//4.4 union�����к��нṹ��
typedef union _testStru4
{
	int		iValLower;
	int		iValUpper;
	struct 
	{
		__int64 llLocation;
	};
}testStru4;
EXPORTDLL_API  void Struct_Union(testStru4 *pStru);

//4.5 �ṹ����Ϊ����ֵ
typedef struct _testStru5
{
	int		iVal;
}testStru5;
testStru5	g_stru5;
EXPORTDLL_API  testStru5* Struct_Return();

//4.6 �ṹ��������Ϊ����
typedef struct _testStru6
{
	int		iVal;
}testStru6;
EXPORTDLL_API  void Struct_StruArr(testStru6 *pStru, int len);

//4.7 �ṹ���к��������������͵Ķ�ά����
typedef struct _testStru7
{
	int		m[5][5];
}testStru7;
EXPORTDLL_API  void Struct_Change2DArr(testStru7 *pStru);

//4.8 �ṹ����Ϊ�����������ͷŷ��йܵ��ڴ�
typedef struct _testStru8
{
	int		m;
}testStru8;
EXPORTDLL_API  void Struct_ParameterOut(testStru8 **ppStru);

//4.9 �ṹ���к����ַ���--ָ��
typedef struct _testStru9
{	
	WCHAR	*pWChArr;
	CHAR	*pChArr;
	bool	IsCbool;
	BOOL	IsBOOL;
}testStru9;
EXPORTDLL_API  void Struct_ChangePtr(testStru9 *pStru);

//4.10 �ṹ����Ƕ�׽ṹ��ָ��
typedef struct _testStru10Pre
{	
	int  iVal;
}testStru10Pre;
typedef struct _testStru10
{	
	testStru10Pre *pPre;
	long		  lVal;
	_testStru10()
	{
		pPre = NULL;
	}
}testStru10;
EXPORTDLL_API  void Struct_NestStruct(testStru10 *pStru);


/************************************************************************/
/*                          5. ������                                    */
/************************************************************************/
//5.1 ��ȡ������
EXPORTDLL_API  void Err_Get();

#ifndef EXPORTDLL_EXPORTS
#pragma comment(lib, "ExportDll.lib")
#endif


#endif //!AFXSTD_860013BE_C31D_4099_9995_6573EC72878A