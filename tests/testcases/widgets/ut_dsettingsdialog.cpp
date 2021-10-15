/*
* Copyright (C) 2021 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     Ye ShanShan <yeshanshan@uniontech.com>
*
* Maintainer: Ye ShanShan <yeshanshan@uniontech.com>>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QIcon>

#include <gtest/gtest.h>

#include "dsettingsdialog.h"
DWIDGET_USE_NAMESPACE
class ut_DSettingsDialog : public testing::Test
{
protected:
    void SetUp() override
    {
        target = new DSettingsDialog();
    }
    void TearDown() override
    {
        if (target) {
            delete target;
            target = nullptr;
        }
    }
    DSettingsDialog *target = nullptr;
};

TEST_F(ut_DSettingsDialog, setGroupVisible)
{
    target->setGroupVisible("setGroupVisible", true);
    ASSERT_EQ(target->groupIsVisible("setGroupVisible"), target->isVisible() && target->groupIsVisible("setGroupVisible"));
};

TEST_F(ut_DSettingsDialog, supplement)
{
    target->widgetFactory();
    QString groupKey = "group1";
    target->setGroupVisible(groupKey, true);
    target->scrollToGroup(groupKey);
    target->setIcon(QIcon::fromTheme("preferences-system"));
}