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

#ifndef NEROPREFERENCES_H
#define NEROPREFERENCES_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class NeroManagerPreferences;
}

class NeroManagerPreferences : public QDialog
{
    Q_OBJECT

public:
    explicit NeroManagerPreferences(QWidget *parent = nullptr);
    ~NeroManagerPreferences();
    void BindSettings(QSettings *);

private slots:
    void on_buttonBox_accepted() { accepted = true; }

private:
    Ui::NeroManagerPreferences *ui;
    QSettings *managerCfg;
    bool accepted = false;
    void on_defaultPrefixStart_clicked();
};

#endif // NEROPREFERENCES_H
