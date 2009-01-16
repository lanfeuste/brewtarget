/*
 * database.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DATABASE_H
#define	_DATABASE_H

#include <vector>
#include <iostream>
#include <fstream>
#include "equipment.h"
#include "fermentable.h"
#include "hop.h"
#include "mash.h"
#include "mashstep.h"
#include "misc.h"
#include "recipe.h"
#include "style.h"
#include "water.h"
#include "yeast.h"

class Database;

class Database
{
public:
   Database();
   static void initialize();
   static bool isInitialized();
   static void savePersistent(); // Save to the persistent medium.

   // The stuff we care about...
   static std::vector<Equipment*> equipments;
   static std::vector<Fermentable*> fermentables;
   static std::vector<Hop*> hops;
   static std::vector<Mash*> mashs;
   static std::vector<MashStep*> mashSteps;
   static std::vector<Misc*> miscs;
   static std::vector<Recipe*> recipes;
   static std::vector<Style*> styles;
   static std::vector<Water*> waters;
   static std::vector<Yeast*> yeasts;

private:
   static bool initialized;
   static std::fstream dbFile;
   static const char* dbFileName;
   static std::fstream recipeFile; // Why are these separate from the dbFile? To prevent duplicates.
   static const char* recipeFileName;
   static std::fstream mashFile; // Why are these separate from the dbFile? To prevent duplicates.
   static const char* mashFileName;
};

#endif	/* _DATABASE_H */
