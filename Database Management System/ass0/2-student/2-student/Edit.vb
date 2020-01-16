Public Class Edit
    Inherits Main
    Private Sub Edit_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        
    End Sub

    Private Sub editButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles editButton.Click
        Dim temproll, tempdcode, tempoption, tempinput As String
        Dim idx, len, flag, tempphone As Integer
        temproll = rolltext1.Text
        tempoption = optioncombo.Text
        tempinput = input.Text

        len = temproll.Length
        If len < 5 Then
            result1.Text = "INVALID ROLL (LENGTH < 5)"
        Else
            idx = -1
            result1.Text = "VALID ROLL"
            tempdcode = temproll.Substring(0, 4)
            If tempdcode = "BCIV" Then
                idx = 0
            ElseIf tempdcode = "BCSE" Then
                idx = 1
            ElseIf tempdcode = "BETC" Then
                idx = 2
            ElseIf tempdcode = "BMEC" Then
                idx = 3
            End If

            If idx = -1 Then
                result1.Text = "INVALID ROLL (INVALID DEPT)"
            Else
                flag = 0
                For i As Integer = 0 To arrDept(idx).totalstudents - 1
                    If temproll = arrStu(idx, i).roll And arrStu(idx, i).isDeleted = 0 Then

                        If tempoption = "Name" Then
                            result0.Text = "DETAILS BEFORE EDIT" & vbCrLf & "ROLL: " & arrStu(idx, i).roll & vbCrLf & "NAME: " & arrStu(idx, i).name & vbCrLf & "DEPT CODE: " & arrStu(idx, i).dcode & vbCrLf & "ADDRESS: " & arrStu(idx, i).address & vbCrLf & "PHONE: " & arrStu(idx, i).phone & vbCrLf
                            arrStu(idx, i).name = tempinput
                            result1.Text = "NAME EDITED SUCCESSFULLY" & vbCrLf & "ROLL: " & arrStu(idx, i).roll & vbCrLf & "NAME: " & arrStu(idx, i).name & vbCrLf & "DEPT CODE: " & arrStu(idx, i).dcode & vbCrLf & "ADDRESS: " & arrStu(idx, i).address & vbCrLf & "PHONE: " & arrStu(idx, i).phone & vbCrLf
                        ElseIf tempoption = "Address" Then
                            result0.Text = "DETAILS BEFORE EDIT" & vbCrLf & "ROLL: " & arrStu(idx, i).roll & vbCrLf & "NAME: " & arrStu(idx, i).name & vbCrLf & "DEPT CODE: " & arrStu(idx, i).dcode & vbCrLf & "ADDRESS: " & arrStu(idx, i).address & vbCrLf & "PHONE: " & arrStu(idx, i).phone & vbCrLf
                            arrStu(idx, i).address = tempinput
                            result1.Text = "ADDRESS EDITED SUCCESSFULLY" & vbCrLf & "ROLL: " & arrStu(idx, i).roll & vbCrLf & "NAME: " & arrStu(idx, i).name & vbCrLf & "DEPT CODE: " & arrStu(idx, i).dcode & vbCrLf & "ADDRESS: " & arrStu(idx, i).address & vbCrLf & "PHONE: " & arrStu(idx, i).phone & vbCrLf
                        ElseIf tempoption = "Phone" Then
                            result0.Text = "DETAILS BEFORE EDIT" & vbCrLf & "ROLL: " & arrStu(idx, i).roll & vbCrLf & "NAME: " & arrStu(idx, i).name & vbCrLf & "DEPT CODE: " & arrStu(idx, i).dcode & vbCrLf & "ADDRESS: " & arrStu(idx, i).address & vbCrLf & "PHONE: " & arrStu(idx, i).phone & vbCrLf
                            tempphone = Val(tempinput)
                            arrStu(idx, i).phone = tempphone
                            result1.Text = "PHONE EDITED SUCCESSFULLY" & vbCrLf & "ROLL: " & arrStu(idx, i).roll & vbCrLf & "NAME: " & arrStu(idx, i).name & vbCrLf & "DEPT CODE: " & arrStu(idx, i).dcode & vbCrLf & "ADDRESS: " & arrStu(idx, i).address & vbCrLf & "PHONE: " & arrStu(idx, i).phone & vbCrLf
                        Else
                            result1.Text = "NO OPTION CHOSEN"
                        End If
                        flag = 1
                    End If
                Next i
                If flag = 0 Then
                    result1.Text = "ROLL NOT FOUND"
                End If
            End If
        End If

    End Sub

    Private Sub cancButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cancButton.Click
        Me.Close()
    End Sub
End Class