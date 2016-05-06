Name: Pratik Gundlupet Venkatesh

Bug ID: 01
Assignment Name: Quiz3 - ConnectX
Platform/OS: Linux/Ubuntu 15.4 x64
Severity: Normal
Summary: TestFailure at 'atPlacePieceOutBounds' testcase
Description: The atPlacePieceOutBounds test-case places a Piece at an invalid location and the tries to verify it from an invalid location
Actual Result: BLACK - 2
Expected Result: INVALID - -1

Bug ID:		02
Assignment Name:Quiz3 - ConnectX
Platform/OS:	Linux/Ubuntu 15.4 x64
Severity:	Normal
Summary:	TestFailure at 'atPlacePieceNegative' testcase
Description:	The atPlacePieceNegative test-case places a Piece at a negative location and the tries to verify it from an invalid location. 			Here the issue is at when the piece is getting placed in negative location, I have commented in the testcase since I cannot 			test further testcases if its uncommented. This issue only occurs when the piece is placed at '-1' location.
Actual Result:	*** Error in `./ConnectXTest': double free or corruption (out): 0x00000000010c8fd0 *** Aborted (core dumped)
Expected Result:EMPTY - 0

Bug ID:		03
Assignment Name:Quiz3 - ConnectX
Platform/OS:	Linux/Ubuntu 15.4 x64
Severity:	Normal
Summary:	TestFailure at 'atWidthOutBounds' and 'atWidthNegative' testcases
Description:	Both atWidthOutBounds & atWidthNegative test-cases places a Piece at a valid location and the tries to verify it from an 			invalid Width location.
Actual Result:	EMPTY - 0
Expected Result:INVALID - -1
