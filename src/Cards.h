#pragma once
/*
 *      Copyright (C) 2005-2011 Team Kodi
 *      https://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <vector>
#include <string>
#include "DateTime.h"


/**
 * MediaPortal TVServer card settings ("card" table in the database)
 */
typedef struct Card
{
  int       IdCard;
  std::string    DevicePath;
  std::string    Name;
  int       Priority;
  bool      GrabEPG;
  MPTV::CDateTime LastEpgGrab;
  std::string    RecordingFolder;
  std::string    RecordingFolderUNC;
  int       IdServer;
  bool      Enabled;
  int       CamType;
  std::string    TimeshiftFolder;
  std::string    TimeshiftFolderUNC;
  int       RecordingFormat;
  int       DecryptLimit;
  bool      Preload;
  bool      CAM;
  int       NetProvider;
  bool      StopGraph;
} Card;

class CCards: public std::vector<Card>
{
  public:

    /**
     * \brief Parse the multi-line string response from the TVServerKodi plugin command "GetCardSettings"
     * The data is stored in "struct Card" item.
     * 
     * \param lines Vector with response lines
     * \return True on success, False on failure
     */
    bool ParseLines(std::vector<std::string>& lines);

    /**
     * \brief Return the data for the card with the given id
     * \param id The card id
     * \param card Return value: card data or NULL if not found.
     * \return True on success, False on failure
     */
    bool GetCard(int id, Card& card);
};
