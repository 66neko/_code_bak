// CPUTemperatureDlg.h : ͷ�ļ�
//

#pragma once


// CCPUTemperatureDlg �Ի���
class CCPUTemperatureDlg : public CDialog
{
// ����
public:
	CCPUTemperatureDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CPUTEMPERATURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
