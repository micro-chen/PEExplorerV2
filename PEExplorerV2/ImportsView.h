#pragma once

#include "GenericListView.h"
#include "PEParser.h"

class ImportsView : public IGenericListViewCallback {
public:
	ImportsView(PEParser* parser);
	void Init(CListViewCtrl& lv);

	// IGenericListViewCallback
	int GetItemCount() override;
	CString GetItemText(int row, int col) override;
	bool Sort(int column, bool ascending) override;
	int GetIcon(int row) override;

	const ImportedLibrary& GetLibrary(int selected) const;

private:
	static bool CompareItems(ImportedLibrary& lib1, ImportedLibrary& lib2, int col, bool asc);

	PEParser* _parser;
	std::vector<ImportedLibrary> _libraries;
};

