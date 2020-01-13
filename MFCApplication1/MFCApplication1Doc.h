
// MFCApplication1Doc.h: interfejs klasy CMFCApplication1Doc
//


#pragma once


class CMFCApplication1Doc : public CDocument
{
protected: // utwórz tylko na podstawie serializacji
	CMFCApplication1Doc() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// Atrybuty
public:

// Operacje
public:

// Przesłania
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementacja
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Wygenerowano funkcje mapy komunikatów
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Funkcja pomocnicza, która ustawia zawartość wyszukiwania dla procedury obsługi wyszukiwania
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
