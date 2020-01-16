Public Class Display
    Inherits Main
    Dim stulist(100) As student
    Dim idx, totalstudents, deptstu As Integer
    Private Sub Display_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Label1.Text = ""
        Label2.Text = ""
        Label3.Text = ""
        Label4.Text = ""
        Label5.Text = ""
        idx = 0
        For i = 0 To 3
            deptstu = arrDept(i).totalstudents
            For j = 0 To deptstu - 1
                If arrStu(i, j).isDeleted = 0 Then
                    stulist(idx) = arrStu(i, j)
                    idx = idx + 1
                End If
            Next j
        Next i
        totalstudents = idx
        Label1.Text = totalstudents
        idx = -5
    End Sub

    Private Sub prevButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles prevButton.Click
        Label1.Text = ""
        Label2.Text = ""
        Label3.Text = ""
        Label4.Text = ""
        Label5.Text = ""
        idx = idx - 5
        If idx < 0 Then
            idx = -5
            Return
        End If
        If idx >= 0 And idx < totalstudents Then
            Label1.Text = "Student " & idx + 1 & vbCrLf & "ROLL: " & stulist(idx).roll & vbCrLf & "NAME: " & stulist(idx).name & vbCrLf & "DEPT CODE: " & stulist(idx).dcode & vbCrLf & "ADDRESS: " & stulist(idx).address & vbCrLf & "PHONE: " & stulist(idx).phone & vbCrLf
            idx = idx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label2.Text = "Student " & idx + 1 & vbCrLf & "ROLL: " & stulist(idx).roll & vbCrLf & "NAME: " & stulist(idx).name & vbCrLf & "DEPT CODE: " & stulist(idx).dcode & vbCrLf & "ADDRESS: " & stulist(idx).address & vbCrLf & "PHONE: " & stulist(idx).phone & vbCrLf
            idx = idx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label3.Text = "Student " & idx + 1 & vbCrLf & "ROLL: " & stulist(idx).roll & vbCrLf & "NAME: " & stulist(idx).name & vbCrLf & "DEPT CODE: " & stulist(idx).dcode & vbCrLf & "ADDRESS: " & stulist(idx).address & vbCrLf & "PHONE: " & stulist(idx).phone & vbCrLf
            idx = idx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label4.Text = "Student " & idx + 1 & vbCrLf & "ROLL: " & stulist(idx).roll & vbCrLf & "NAME: " & stulist(idx).name & vbCrLf & "DEPT CODE: " & stulist(idx).dcode & vbCrLf & "ADDRESS: " & stulist(idx).address & vbCrLf & "PHONE: " & stulist(idx).phone & vbCrLf
            idx = idx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label5.Text = "Student " & idx + 1 & vbCrLf & "ROLL: " & stulist(idx).roll & vbCrLf & "NAME: " & stulist(idx).name & vbCrLf & "DEPT CODE: " & stulist(idx).dcode & vbCrLf & "ADDRESS: " & stulist(idx).address & vbCrLf & "PHONE: " & stulist(idx).phone & vbCrLf
            idx = idx + 1
        End If
        idx = idx - 5
    End Sub

    Private Sub nextButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles nextButton.Click
        Label1.Text = ""
        Label2.Text = ""
        Label3.Text = ""
        Label4.Text = ""
        Label5.Text = ""
        If idx < totalstudents Then
            idx = idx + 5
        End If
        Dim tempidx As Integer
        tempidx = idx
        If idx >= 0 And idx < totalstudents Then
            Label1.Text = "Student " & tempidx + 1 & vbCrLf & "ROLL: " & stulist(tempidx).roll & vbCrLf & "NAME: " & stulist(tempidx).name & vbCrLf & "DEPT CODE: " & stulist(tempidx).dcode & vbCrLf & "ADDRESS: " & stulist(tempidx).address & vbCrLf & "PHONE: " & stulist(tempidx).phone & vbCrLf
            tempidx = tempidx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label2.Text = "Student " & tempidx + 1 & vbCrLf & "ROLL: " & stulist(tempidx).roll & vbCrLf & "NAME: " & stulist(tempidx).name & vbCrLf & "DEPT CODE: " & stulist(tempidx).dcode & vbCrLf & "ADDRESS: " & stulist(tempidx).address & vbCrLf & "PHONE: " & stulist(tempidx).phone & vbCrLf
            tempidx = tempidx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label3.Text = "Student " & tempidx + 1 & vbCrLf & "ROLL: " & stulist(tempidx).roll & vbCrLf & "NAME: " & stulist(tempidx).name & vbCrLf & "DEPT CODE: " & stulist(tempidx).dcode & vbCrLf & "ADDRESS: " & stulist(tempidx).address & vbCrLf & "PHONE: " & stulist(tempidx).phone & vbCrLf
            tempidx = tempidx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label4.Text = "Student " & tempidx + 1 & vbCrLf & "ROLL: " & stulist(tempidx).roll & vbCrLf & "NAME: " & stulist(tempidx).name & vbCrLf & "DEPT CODE: " & stulist(tempidx).dcode & vbCrLf & "ADDRESS: " & stulist(tempidx).address & vbCrLf & "PHONE: " & stulist(tempidx).phone & vbCrLf
            tempidx = tempidx + 1
        End If
        If idx >= 0 And idx < totalstudents Then
            Label5.Text = "Student " & tempidx + 1 & vbCrLf & "ROLL: " & stulist(tempidx).roll & vbCrLf & "NAME: " & stulist(tempidx).name & vbCrLf & "DEPT CODE: " & stulist(tempidx).dcode & vbCrLf & "ADDRESS: " & stulist(tempidx).address & vbCrLf & "PHONE: " & stulist(tempidx).phone & vbCrLf
            tempidx = tempidx + 1
        End If
        
    End Sub

End Class