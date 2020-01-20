// Copyright (c) 2017-2019 The sssolutions developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef zsssCONTROLDIALOG_H
#define zsssCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zsss/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class zsssControlDialog;
}

class CzsssControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CzsssControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CzsssControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CzsssControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class zsssControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zsssControlDialog(QWidget *parent);
    ~zsssControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::zsssControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CzsssControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // zsssCONTROLDIALOG_H
