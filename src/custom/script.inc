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

/**
* โหลดไฟล์สคริป
* import "<filename>"
**/
BUILDIN_FUNC(import) {
	const char *filename = script_getstr(st, 2);

	npc_addsrcfile(filename);
	npc_parsesrcfile(filename, true);
	npc_read_event_script();

	return SCRIPT_CMD_SUCCESS;
}
