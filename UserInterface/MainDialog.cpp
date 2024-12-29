/*
 * Rosalie's Mupen GUI - https://github.com/Rosalie241/RMG
 *  Copyright (C) 2020 Rosalie Wanders <rosalie@mailbox.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3.
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "MainDialog.hpp"
#include "m64p_types.h"
#include "m64p_config.h"
#include "../parallel.h"

#include <QRegularExpression>

using namespace UserInterface;

MainDialog::MainDialog(QWidget* parent) : QDialog(parent)
{
    this->setupUi(this);

    this->hleGFXCheckBox->setChecked(ConfigGetParamBool(configRspParallel, KEY_HLE_GFX));
    this->hleAUDCheckBox->setChecked(ConfigGetParamBool(configRspParallel, KEY_HLE_AUD));
}

MainDialog::~MainDialog()
{
}

void MainDialog::on_buttonBox_clicked(QAbstractButton* button)
{
    QPushButton *pushButton = (QPushButton *)button;
    QPushButton *okButton = this->buttonBox->button(QDialogButtonBox::Ok);
    QPushButton *defaultButton = this->buttonBox->button(QDialogButtonBox::RestoreDefaults);

    if (pushButton == okButton)
    {
        int hleGFX = this->hleGFXCheckBox->isChecked() ? 1 : 0;
        int hleAUD = this->hleAUDCheckBox->isChecked() ? 1 : 0;

        ConfigSetParameter(configRspParallel, KEY_HLE_GFX, M64TYPE_BOOL, &hleGFX);
        ConfigSetParameter(configRspParallel, KEY_HLE_AUD, M64TYPE_BOOL, &hleAUD);

        ConfigSaveSection("RSP-Parallel");
    }
    else if (pushButton == defaultButton)
    {
        this->hleGFXCheckBox->setChecked(false);
        this->hleAUDCheckBox->setChecked(false);
    }
}
