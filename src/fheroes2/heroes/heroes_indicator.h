/***************************************************************************
 *   Copyright (C) 2009 by Andrey Afletdinov <fheroes2@gmail.com>          *
 *                                                                         *
 *   Part of the Free Heroes2 Engine:                                      *
 *   http://sourceforge.net/projects/fheroes2                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#pragma once

#include <string>

class Heroes;

class HeroesIndicator
{
public:
    HeroesIndicator(const Heroes&);

    const Rect& GetArea() const;

    const string& GetDescriptions() const;

    void SetPos(const Point&, bool skip_back = false);

protected:
    const Heroes& hero;
    Rect area;
    SpriteBack back;
    string descriptions;
};

class LuckIndicator : public HeroesIndicator
{
public:
    LuckIndicator(const Heroes&);

    void Redraw();

    static void QueueEventProcessing(LuckIndicator&);

private:
    int luck;
};

class MoraleIndicator : public HeroesIndicator
{
public:
    MoraleIndicator(const Heroes&);

    void Redraw();

    static void QueueEventProcessing(MoraleIndicator&);

private:
    int morale;
};

class ExperienceIndicator : public HeroesIndicator
{
public:
    ExperienceIndicator(const Heroes&);

    void Redraw() const;

    void QueueEventProcessing() const;
};

class SpellPointsIndicator : public HeroesIndicator
{
public:
    SpellPointsIndicator(const Heroes&);

    void Redraw() const;

    void QueueEventProcessing() const;
};
