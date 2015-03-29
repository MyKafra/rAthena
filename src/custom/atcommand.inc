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
