// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

/**
 * Custom Atcommands
 * Place the body of custom atcommands in this file.
 * Format:
 *	ACMD_FUNC(command_name)
 *	{
 *		<code>;
 *	}
 **/

//ACMD_FUNC(newcommand)
//{
//	clif_displaymessage(fd, "It works!");
//	clif_specialeffect(&sd->bl, 343, AREA);
//	return 0;
//}

/**
* Fake players online in game [Mr.Postman]
* Usage: @fakeuser <number>
*/
ACMD_FUNC(fakeuser) {
	int num = 0;

	memset(atcmd_output, '\0', sizeof(atcmd_output));

	if (!message || !*message || sscanf(message, "%d", &num) < 1) {
		sprintf(atcmd_output, "Usage: @fakeuser <number>.");
		clif_displaymessage(fd, atcmd_output);
		return -1;
	}

	fake_users += num;

	if (fake_users < 0)
		fake_users = 0;

	return 0;
}

/**
* เรียกผู้เล่นทำหมดจากแผนที่เป้าหมาย [Mr.Postman]
* Usage: @recallmap <mapname>
*/
ACMD_FUNC(recallmap) {
	char map_name[MAP_NAME_LENGTH];
	unsigned short mapindex;
	int16 m = -1;
	struct s_mapiterator *iter;
	struct map_session_data *pl_sd;

	if (!message || !*message || sscanf(message, "%11s", map_name) < 1) {
		clif_displaymessage(fd, "Please enter a map (usage: @recallmap <mapname>.");
		return -1;
	}

	mapindex = mapindex_name2id(map_name);

	if (mapindex)
		m = map_mapindex2mapid(mapindex);

	if (!mapindex) {
		clif_displaymessage(fd, msg_txt(sd, 1));
		return -1;
	}
	
	iter = mapit_getallusers();
	for (pl_sd = (TBL_PC*)mapit_first(iter); mapit_exists(iter); pl_sd = (TBL_PC*)mapit_next(iter)) {
		if (pl_sd->status.char_id == sd->status.char_id)
			continue;

		if (pl_sd->bl.m != m)
			continue;

		if (pc_isdead(pl_sd) || pc_istrading(pl_sd))
			continue;

		pc_setpos(pl_sd, sd->mapindex, sd->bl.x, sd->bl.y, CLR_RESPAWN);
	}
	mapit_free(iter);

	return 0;
}
