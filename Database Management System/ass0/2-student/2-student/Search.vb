Public Class Search
    Inherits Main
    Private Sub Search_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub

    Private Sub searchButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles searchButton.Click
        Dim temproll, tempdcode As String
        Dim idx, len, flag As Integer
        temproll = rolltext1.Text
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
                        result1.Text = "ROLL FOUND" & vbCrLf & "ROLL: " & arrStu(idx, i).roll & vbCrLf & "NAME: " & arrStu(idx, i).name & vbCrLf & "DEPT CODE: " & arrStu(idx, i).dcode & vbCrLf & "ADDRESS: " & arrStu(idx, i).address & vbCrLf & "PHONE: " & arrStu(idx, i).phone & vbCrLf
                        flag = 1
                    End If
                Next i
                If flag = 0 Then
                    result1.Text = "ROLL NOT FOUND"
                End If
            End If
        End If
        
    End Sub
End Class