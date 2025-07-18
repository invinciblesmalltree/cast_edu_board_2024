// Copyright (C) 2023 ArcticLampyrid <alampy.com>
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "ease_out_quint_animation.h"
#include <valarray>

ease_out_quint_animation::ease_out_quint_animation(float init_value) : animation(init_value)
{
}

float ease_out_quint_animation::map(float t)
{
    return 1.f - std::pow(1.f - t, 5.f);
}
