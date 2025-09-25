/*  Nero Launcher: A very basic Bottles-like manager using UMU.
    GUI Manager Settings dialog.

    Copyright (C) 2024 That One Seong

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "neropreferences.h"
#include "nerofs.h"
#include "ui_neropreferences.h"

#include <QShortcut>
#include <QCheckBox>

NeroManagerPreferences::NeroManagerPreferences(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NeroManagerPreferences)
{
    ui->setupUi(this);
    // make window non-resizeable
    setFixedSize(sizeHint());

    // shortcut ctrl/cmd + W to close the popup window
	QShortcut *shortcutClose = new QShortcut(QKeySequence::Close, this);
	connect(shortcutClose, &QShortcut::activated, this,&NeroManagerPreferences::close);

    ui->defaultPrefix->addItems(NeroFS::GetPrefixes());
    connect(ui->defaultPrefixStart, &QCheckBox::clicked, this, &NeroManagerPreferences::on_defaultPrefixStart_clicked);
}

NeroManagerPreferences::~NeroManagerPreferences()
{
    if(accepted) {
        //managerCfg->setValue("UseNotifier", ui->runnerNotifs->isChecked());
        managerCfg->setValue("ShortcutHidesManager", ui->shortcutHide->isChecked());
        managerCfg->setValue("RunWithDefaultPrefix", ui->defaultPrefixStart->isChecked());
        managerCfg->setValue("DefaultPrefix", ui->defaultPrefix->currentText());
    }
    delete ui;
}

void NeroManagerPreferences::BindSettings(QSettings *cfg)
{
    managerCfg = cfg;
    //ui->runnerNotifs->setChecked(managerCfg->value("UseNotifier").toBool());
    ui->shortcutHide->setChecked(managerCfg->value("ShortcutHidesManager").toBool());
    ui->defaultPrefixStart->setChecked(managerCfg->value("RunWithDefaultPrefix").toBool());
    ui->defaultPrefix->setCurrentText(managerCfg->value("DefaultPrefix").toString());
    ui->defaultPrefix->setEnabled(ui->defaultPrefixStart->isChecked());
}

void NeroManagerPreferences::on_defaultPrefixStart_clicked()
{
    ui->defaultPrefix->setEnabled(ui->defaultPrefixStart->isChecked());
}