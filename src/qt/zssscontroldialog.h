// Copyright (c) 2017-2020 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZSSSCONTROLDIALOG_H
#define ZSSSCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zsss/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class zSSSControlDialog;
}

class CzSSSControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CzSSSControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CzSSSControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CzSSSControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class zSSSControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zSSSControlDialog(QWidget *parent);
    ~zSSSControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::zSSSControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CzSSSControlWidgetItem;

private Q_SLOTS:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZSSSCONTROLDIALOG_H
