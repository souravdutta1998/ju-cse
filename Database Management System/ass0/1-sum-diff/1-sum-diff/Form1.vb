Public Class Form1
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Me.Text = "Calculator! Current Date: " + Date.Today
    End Sub

    Private Sub sumButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles sumButton.Click
        Dim val1, val2 As Integer
        val1 = Val(num1.Text)
        val2 = Val(num2.Text)
        result.Text = val1 + val2
    End Sub

    Private Sub diffButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles diffButton.Click
        Dim val1, val2 As Integer
        val1 = Val(num1.Text)
        val2 = Val(num2.Text)
        result.Text = val1 - val2
    End Sub
End Class
