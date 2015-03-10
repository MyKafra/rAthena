// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

/**
 * Custom Script Commands
 * Place the body of custom script commands in this file.
 * Format:
 *	BUILDIN_FUNC(command_name)
 *	{
 *		<code>;
 *	}
 **/

//BUILDIN_FUNC(example)
//{
//	ShowInfo("buildin_example: It works!\n");
//	script_pushint(st,1);
//	return 0;
//}

BUILDIN_FUNC(import)
{
	const char *file = script_getstr(st, 2);

	npc_addsrcfile(file);
	npc_parsesrcfile(file, true);
	npc_read_event_script();
	
	return 0;
}

BUILDIN_FUNC(showequip)
{
	struct map_session_data *sd = script_rid2sd(st);
	int flag;

	if (sd == NULL)
		return 0;

	flag = script_getnum(st, 2);
	
	if (flag == 1)
		sd->status.show_equip = true;
	else
		sd->status.show_equip = false;
	
	clif_equiptickack(sd, flag);
		
	return 0;
}
